/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  7 Oct 2011 4:22:25pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SAMPLERCOMPONENT_SAMPLERCOMPONENT_1DC5000B__
#define __JUCER_HEADER_SAMPLERCOMPONENT_SAMPLERCOMPONENT_1DC5000B__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioPlayer.h"
#include "WaveformDisplayComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SamplerComponent  : public Component,
                          public ButtonListener,
                          public SliderListener
{
public:
    //==============================================================================
    SamplerComponent ();
    ~SamplerComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.



    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	AudioPlayer* audioPlayer;

    //[/UserVariables]

    //==============================================================================
    TextButton* fileButton;
    Label* chooseLabel;
    Slider* speedSlider;
    Label* speedLabel;
    Slider* gainSlider;
    Label* sustainLabel;
    ToggleButton* chopButton;
    Slider* chopSlider;
    Label* chopLabel;
    Slider* chopRepeatProbSlider;
    Label* chopRepeatProbLabel;
    Slider* chopAdvanceProbSlider;
    Label* chopAdvanceProbLabel;
    WaveformDisplayComponent* waveformDisplayComponent;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    SamplerComponent (const SamplerComponent&);
    const SamplerComponent& operator= (const SamplerComponent&);
};


#endif   // __JUCER_HEADER_SAMPLERCOMPONENT_SAMPLERCOMPONENT_1DC5000B__
