/*
  ==============================================================================

    FilePlayer.h
    Created: 3 Oct 2011 3:49:29pm
    Author:  bchang

  ==============================================================================
*/

#ifndef __FILEPLAYER_H_2C333EB0__
#define __FILEPLAYER_H_2C333EB0__

#include "../JuceLibraryCode/JuceHeader.h"

class AudioPlayer  : public AudioIODeviceCallback, public MultiTimer
{
public:
    //==============================================================================
    AudioPlayer ();
    ~AudioPlayer();

	void audioDeviceIOCallback(const float** inputChannelData,
							   int totalNumInputChannels,
							   float** outputChannelData,
							   int totalNumOutputChannels,
							   int numSamples);
	
	void audioDeviceAboutToStart (AudioIODevice* device);
    void audioDeviceStopped();
	
	void playSample();
	void setFile(File audioFile);
	
	void changeSpeed(double ratio);
	void changeGain(float gain);
	
	void timerCallback(int timerID);
	void setRandParam(bool b);
	void setTranspRate(int hz);
	void setSkipRate(int hz);
	void setTranspRange(float max);
    
private:
	
	bool randParam;
	int randHz;
	double transpRange;
	double masterGain;
	int randPos;
	
	double sineInc;
	double sineFreq;
	int totalPosLength;
	
	// this wraps the actual audio device
    AudioDeviceManager audioDeviceManager;
	
    // this allows an audio source to be streamed to the IO device
    AudioSourcePlayer audioSourcePlayer;
	
    // this controls the playback of a positionable audio stream, handling the
    // starting/stopping and sample-rate conversion
    AudioTransportSource transportSource;
	
    // this source is used to mix together the output from our synth source
    // and wave player source
    MixerAudioSource mixerSource;
	
    // this is the actual stream that's going to read from the audio file.
    AudioFormatReaderSource* currentAudioFileSource;
	
	ResamplingAudioSource* resamplingAudioSource;
	ResamplingAudioSource* masterResamplingSource;
	
    File currentFile;
	

};




#endif  // __FILEPLAYER_H_2C333EB0__
