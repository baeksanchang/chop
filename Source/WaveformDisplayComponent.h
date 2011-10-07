/*
  ==============================================================================

    WaveformDisplayComponent.h
    Created: 7 Oct 2011 3:40:34pm
    Author:  Baek Chang

  ==============================================================================
*/

#ifndef __WAVEFORMDISPLAYCOMPONENT_H_3CD5659C__
#define __WAVEFORMDISPLAYCOMPONENT_H_3CD5659C__

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/* This component scrolls a continuous waveform showing the audio that's currently
 coming into the audio input.
 */
class WaveformDisplayComponent  : public Component,
public Timer
{
public:
    //==============================================================================
    WaveformDisplayComponent();
    ~WaveformDisplayComponent();
	
    void paint (Graphics& g);
    void timerCallback();
	
    void clearWaveformSampleData();
    void drawWaveform (const float** inputChannelData, int numInputChannels, int numSamples);	
	
private:
    float samples [1024];
    int nextSample, subSample;
    float accumulator;
	int numSubSamples; // how many input samples go onto one pixel.

    WaveformDisplayComponent (const WaveformDisplayComponent&);
    WaveformDisplayComponent& operator= (const WaveformDisplayComponent&);
};


#endif  // __WAVEFORMDISPLAYCOMPONENT_H_3CD5659C__
