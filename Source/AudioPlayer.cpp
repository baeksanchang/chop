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
	//initialize to default audio device
	audioDeviceManager.initialise (1, /* number of input channels */
								   2, /* number of output channels */
								   0, /* no XML settings.. */
								   true  /* select default device on failure */);
	
	currentAudioFileSource = 0;
	AudioFormatManager formatManager;
	formatManager.registerBasicFormats();

	// resampler for our transport source (file input)
	resamplingAudioSource = new ResamplingAudioSource(&transportSource, true);

	// connect resampled source as the input for the audioSourcePlayer
	audioSourcePlayer.setSource (resamplingAudioSource);
	
	// start the IO device pulling its data from our callback..
	audioDeviceManager.addAudioCallback (this);
}

AudioPlayer::~AudioPlayer()
{
	audioDeviceManager.removeAudioCallback (this);
	transportSource.setSource (0);
	deleteAndZero (currentAudioFileSource);
	audioSourcePlayer.setSource (0);
}

void AudioPlayer::audioDeviceIOCallback(const float** inputChannelData,
						   int totalNumInputChannels,
						   float** outputChannelData,
						   int totalNumOutputChannels,
						   int numSamples)

{
	// pass the audio callback to our player source
	audioSourcePlayer.audioDeviceIOCallback (inputChannelData, totalNumInputChannels, outputChannelData, totalNumOutputChannels, numSamples);
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
	currentAudioFileSource->setLooping(true); // loop it
}

void AudioPlayer::setFile(File audioFile)
{
	transportSource.stop();
	transportSource.setSource (0);
	deleteAndZero (currentAudioFileSource);
	
	// get a format manager and set it up with the basic types (wav and aiff).
	AudioFormatManager formatManager;
	formatManager.registerBasicFormats();
	
	AudioFormatReader* reader = formatManager.createReaderFor (audioFile);

	if (reader != 0)
	{
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
	transportSource.setGain(masterGain);	
}
