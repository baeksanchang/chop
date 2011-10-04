/*
  ==============================================================================

    FilePlayer.cpp
    Created: 3 Oct 2011 3:49:29pm
    Author:  bchang

  ==============================================================================
*/

#include "AudioPlayer.h"
#include <iostream>

AudioPlayer::AudioPlayer(){
	
	randParam = false;
	
	//initialize to default audio device
	audioDeviceManager.initialise (1, /* number of input channels */
								   2, /* number of output channels */
								   0, /* no XML settings.. */
								   true  /* select default device on failure */);
	
	currentAudioFileSource = 0;
	AudioFormatManager formatManager;
	formatManager.registerBasicFormats();
	
	resamplingAudioSource = new ResamplingAudioSource(&transportSource, true);   // resampler for our transport source (file input)
	
	// add the audio source to our mixer..
	mixerSource.addInputSource (resamplingAudioSource, false);
	
	masterResamplingSource = new ResamplingAudioSource(&mixerSource, true); //now resample the mixer output
	
	// ..and connect the mixer to our source player.
	audioSourcePlayer.setSource (masterResamplingSource);
	
	// start the IO device pulling its data from our callback..
	audioDeviceManager.addAudioCallback (this);
	
	startTimer(1, 50);
	startTimer(2, 50);

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

void AudioPlayer::playSample(){

	transportSource.setPosition (0.0);
	transportSource.start();
	currentAudioFileSource->setLooping(true); // loop it
}

void AudioPlayer::setFile(File audioFile){
	
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

void AudioPlayer::changeSpeed(double ratio){

	masterResamplingSource->setResamplingRatio(ratio);
	
}

void AudioPlayer::changeGain(float gain){
	
	masterGain = (double)gain;
	transportSource.setGain(masterGain);
	
}

void AudioPlayer::timerCallback(int timerID){

	if (randParam){  // if the toggle button has been selected
	
		if (timerID == 1){
			sineFreq+=sineInc; //increment determined by frequency in setRandTransRate()
			double sineRate = 0.5*transpRange*(sin(6.28*sineFreq)+1);
			resamplingAudioSource->setResamplingRatio(1.0+sineRate);
		
			if(sineInc >= 1) sineInc = 0;
		}
	
		else if (timerID == 2){
			randPos = rand()%totalPosLength;
			transportSource.setNextReadPosition(randPos);
		}
	
	}
	
}

void AudioPlayer::setRandParam(bool b){

	randParam = b;
	
}

void AudioPlayer::setTranspRate(int hz){
	
	int oldMS1 = getTimerInterval(1);
	int oldMS2 = getTimerInterval(2);
	
	
	
	if (hz == 0){
		resamplingAudioSource->setResamplingRatio(1.0);
		stopTimer(1);
	}
	else{
	
		stopTimer(1);
	
		sineInc = 0.01*hz;
	
		startTimer(1, oldMS1);
		if(isTimerRunning(2)){ //sync the timer starts
			stopTimer(2);
			startTimer(2, oldMS2);
		}
	}
	
}

void AudioPlayer::setSkipRate(int hz){
	
	int oldMS1 = getTimerInterval(2);
	
	if(hz == 0){
		stopTimer(2);
	}
	else {

		stopTimer(2);
		
		int ms = (1/ (double) hz) * 1000.;
		
		startTimer(2, ms);
	
		if(isTimerRunning(1)){ //sync the timer starts
			stopTimer(1);
			startTimer(1, oldMS1);
		}
	}
	
}

void AudioPlayer::setTranspRange(float max){
	
	transpRange = (double)max;
	
}

