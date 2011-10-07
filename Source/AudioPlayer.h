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
#include "WaveformDisplayComponent.h"

class AudioPlayer  : public AudioIODeviceCallback
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

	void setChopEnable(bool set);
	void setChopAmount(int length);
    void performChop(int numSamples);
    bool nextBool(double probability);
	void setChopRepeatProbability(double prob);
	void setChopAdvanceProbability(double prob);

	void setWaveformDisplayComponent(WaveformDisplayComponent *wf);

private:
	
	double masterGain;
	int totalPosLength;

	int chopAmount;
	int chopCounter;
	int chopLeftOver;
	int chopSeekPosition;
	bool chopping;

	double chopRepeatProbability;
	double chopAdvanceProbability;

	// this wraps the actual audio device
    AudioDeviceManager audioDeviceManager;
	
    // this allows an audio source to be streamed to the IO device
    AudioSourcePlayer audioSourcePlayer;
	
    // this controls the playback of a positionable audio stream, handling the
    // starting/stopping and sample-rate conversion
    AudioTransportSource transportSource;

    // this is the actual stream that's going to read from the audio file.
    AudioFormatReaderSource* currentAudioFileSource;
	
	ResamplingAudioSource* resamplingAudioSource;
	
    File currentFile;

	WaveformDisplayComponent *waveform;
};




#endif  // __FILEPLAYER_H_2C333EB0__
