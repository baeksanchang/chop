/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  10 Dec 2009 11:24:45 am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SAMPLERCOMPONENT_SAMPLERCOMPONENT_C7F40330__
#define __JUCER_HEADER_SAMPLERCOMPONENT_SAMPLERCOMPONENT_C7F40330__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioPlayer.h"
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
    ToggleButton* randToggleButton;
    Slider* transpRangeSlider;
    Label* sustainLabel2;
    Slider* transpRateSlider;
    Label* sustainLabel3;
    Slider* skipRateSlider;
    Label* sustainLabel4;
    Path internalPath1;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    SamplerComponent (const SamplerComponent&);
    const SamplerComponent& operator= (const SamplerComponent&);
};


#endif   // __JUCER_HEADER_SAMPLERCOMPONENT_SAMPLERCOMPONENT_C7F40330__
