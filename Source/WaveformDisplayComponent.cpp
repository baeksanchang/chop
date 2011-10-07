/*
  ==============================================================================

    WaveformDisplayComponent.cpp
    Created: 7 Oct 2011 3:40:34pm
    Author:  Baek Chang

  ==============================================================================
*/

#include "WaveformDisplayComponent.h"

WaveformDisplayComponent::WaveformDisplayComponent()
{
    nextSample = subSample = 0;
    accumulator = 0;
	numSubSamples = 200;
	zeromem (samples, sizeof (samples));
    setOpaque (true);
	
    startTimer (1000 / 50); // use a timer to keep repainting this component
}

WaveformDisplayComponent::~WaveformDisplayComponent()
{
}

void WaveformDisplayComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
	
    g.setColour (Colours::purple);
    const float midY = getHeight() * 0.5f;
    int sampleNum = (nextSample + numElementsInArray (samples) - 1);
	
    for (int x = jmin (getWidth(), numElementsInArray (samples)); --x >= 0;)
    {
        const float sampleSize = midY * samples [sampleNum-- % numElementsInArray (samples)];
        g.drawVerticalLine (x, midY - sampleSize, midY + sampleSize);
    }
}

void WaveformDisplayComponent::timerCallback()
{
    repaint();
}

void WaveformDisplayComponent::clearWaveformSampleData()
{
    zeromem (samples, sizeof (samples));
}

void WaveformDisplayComponent::drawWaveform (const float** inputChannelData, int numInputChannels,
											 int numSamples)
{
    for (int i = 0; i < numSamples; ++i)
    {
        for (int chan = 0; chan < numInputChannels; ++chan)
        {
            if (inputChannelData[chan] != 0)
                accumulator += fabsf (inputChannelData[chan][i]);
        }

        if (subSample == 0)
        {
            samples[nextSample] = accumulator / numSubSamples;
            nextSample = (nextSample + 1) % numElementsInArray (samples);
            subSample = numSubSamples;
            accumulator = 0;
        }
        else
        {
            --subSample;
        }
    }
}
