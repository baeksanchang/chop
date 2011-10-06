/*
  ==============================================================================

    FilePlayer.cpp
    Created: 3 Oct 2011 3:49:29pm
    Author:  bchang

  ==============================================================================
*/

#include "AudioPlayer.h"
#include <iostream>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

AudioPlayer::AudioPlayer()
{
	int numOutputChannels = 2, numInputChannels = 0;

	chopping = false;
	chopAmount = 0;
	chopCounter = 0;
	chopLeftOver = 0;
	chopSeekPosition = 0;

	//initialize to default audio device
	audioDeviceManager.initialise (numInputChannels, /* number of input channels */
								   numOutputChannels, /* number of output channels */
								   0, /* no XML settings.. */
								   true  /* select default device on failure */);
	
	currentAudioFileSource = NULL;
	AudioFormatManager formatManager;
	formatManager.registerBasicFormats();

	// resampler for our transport source (file input)
	resamplingAudioSource = new ResamplingAudioSource(&transportSource, true, numOutputChannels);

	// connect resampled source as the input for the audioSourcePlayer
	audioSourcePlayer.setSource (resamplingAudioSource);
	
	// start the IO device pulling its data from our callback..
	audioDeviceManager.addAudioCallback (this);
}

AudioPlayer::~AudioPlayer()
{
	audioDeviceManager.removeAudioCallback (this);
	
	if (transportSource.isPlaying())
		transportSource.stop();
	transportSource.setSource (NULL);
	
	if (currentAudioFileSource)
		deleteAndZero (currentAudioFileSource);

	audioSourcePlayer.setSource (NULL);
}

void AudioPlayer::audioDeviceIOCallback(const float** inputChannelData,
						   int totalNumInputChannels,
						   float** outputChannelData,
						   int totalNumOutputChannels,
						   int numSamples)

{
	// Create a buffer that points to outputChannelData
	AudioSampleBuffer outputBuffer (outputChannelData, totalNumOutputChannels, numSamples);
	
	AudioSourceChannelInfo info;
	info.buffer = &outputBuffer;
	info.startSample = 0;
	info.numSamples = numSamples;

	if (chopping && transportSource.isPlaying())
		performChop(numSamples);

	// Gets the audio buffer from resamplingAudioSource and stores it to outputBuffer
	// So, outputChannelData now stores the audio from the file transport stream
	resamplingAudioSource->getNextAudioBlock (info);

	// do audio processing here, for example gain is applied to audio samples
	for (int i = 0; i < numSamples; i++) {
		outputChannelData[0][i] *= masterGain;
		outputChannelData[1][i] *= masterGain;
	}
}

void AudioPlayer::audioDeviceAboutToStart (AudioIODevice* device)
{
	audioSourcePlayer.audioDeviceAboutToStart (device);
}

void AudioPlayer::audioDeviceStopped()
{
	audioSourcePlayer.audioDeviceStopped();
}

void AudioPlayer::playSample()
{
	transportSource.setPosition (0.0);
	transportSource.start();

	// check if audio file is set, or else it will crash
	if (currentAudioFileSource)
		currentAudioFileSource->setLooping(true);
}

void AudioPlayer::setFile(File audioFile)
{
	if (transportSource.isPlaying()) {
		transportSource.stop();
		transportSource.setSource (NULL);
	}

	if (currentAudioFileSource)
		deleteAndZero (currentAudioFileSource);
	
	// get a format manager and set it up with the basic types (wav and aiff).
	AudioFormatManager formatManager;
	formatManager.registerBasicFormats();
	
	AudioFormatReader* reader = formatManager.createReaderFor (audioFile);

	if (reader != NULL) {
		currentFile = audioFile;

		currentAudioFileSource = new AudioFormatReaderSource (reader, true);
		
		// ..and plug it into our transport source
		transportSource.setSource (currentAudioFileSource,
								   reader->sampleRate*2, // tells it to buffer this many samples ahead
								   reader->sampleRate);

		chopAmount = MIN(transportSource.getTotalLength(), chopAmount);
	}

	totalPosLength = transportSource.getTotalLength();
}

void AudioPlayer::changeSpeed(double ratio)
{
	resamplingAudioSource->setResamplingRatio(ratio);
}

void AudioPlayer::changeGain(float gain)
{	
	masterGain = (double) gain;
}

void AudioPlayer::setChopEnable(bool set)
{
	if (set == false) {
        chopCounter = 0;
        chopLeftOver = 0;
        chopSeekPosition = 0;
	} else {
        if (currentAudioFileSource)
            chopSeekPosition = MAX(0, transportSource.getNextReadPosition() - chopAmount);
    }
	chopping = set;
}

void AudioPlayer::performChop(int numSamples)
{
    // Start of the chop
    if (chopCounter == 0) {
        // With some probability, start the chop or let the stream keep playing.
        // Keep count anyway to determime where chop would've ended in any case.
        if (nextBool(0.6))        
            transportSource.setNextReadPosition(chopSeekPosition);
        chopLeftOver = 0;
    }
    
    chopCounter += numSamples;
    int chopLeftOver = chopCounter - chopAmount;

    // End of the chop
    if (chopLeftOver >= 0)
    {
        chopCounter = 0;
        // With some probability, advance the chop point.
        if (nextBool(0.2))
            chopSeekPosition = MAX(0, transportSource.getNextReadPosition());
    }
}

void AudioPlayer::setChopAmount(int length)
{
	chopAmount = length;
}

// TODO: Bad code design to put this function here, move it somewhere else later
bool AudioPlayer::nextBool(double probability)
{
    return rand() <  probability * RAND_MAX;
}
