/*
  ==============================================================================

    FilePlayer.cpp
    Created: 3 Oct 2011 3:49:29pm
    Author:  bchang

  ==============================================================================
*/

#include "AudioPlayer.h"
#include <iostream>

AudioPlayer::AudioPlayer()
{
	int numOutputChannels = 2, numInputChannels = 0;

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
		currentAudioFileSource->setLooping(true); // loop it
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
								   32768, // tells it to buffer this many samples ahead
								   reader->sampleRate);
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
