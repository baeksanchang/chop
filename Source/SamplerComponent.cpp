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

//[Headers] You can add your own extra header files here...
#include <iostream>
//[/Headers]

#include "SamplerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...



//[/MiscUserDefs]

//==============================================================================
SamplerComponent::SamplerComponent ()
    : fileButton (0),
      chooseLabel (0),
      speedSlider (0),
      speedLabel (0),
      gainSlider (0),
      sustainLabel (0),
      randToggleButton (0),
      transpRangeSlider (0),
      sustainLabel2 (0),
      transpRateSlider (0),
      sustainLabel3 (0),
      skipRateSlider (0),
      sustainLabel4 (0)
{
    addAndMakeVisible (fileButton = new TextButton (T("new button")));
    fileButton->setButtonText (T("file"));
    fileButton->addListener (this);
    fileButton->setColour (TextButton::buttonColourId, Colour (0xfffdfdfd));

    addAndMakeVisible (chooseLabel = new Label (T("new label"),
                                                T("choose file...")));
    chooseLabel->setFont (Font (15.0000f, Font::plain));
    chooseLabel->setJustificationType (Justification::centredLeft);
    chooseLabel->setEditable (false, false, false);
    chooseLabel->setColour (Label::textColourId, Colours::white);
    chooseLabel->setColour (TextEditor::textColourId, Colours::black);
    chooseLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (speedSlider = new Slider (T("new slider")));
    speedSlider->setRange (-10, 10, 0.1);
    speedSlider->setSliderStyle (Slider::Rotary);
    speedSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    speedSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ffff));
    speedSlider->addListener (this);

    addAndMakeVisible (speedLabel = new Label (T("new label"),
                                               T("speed")));
    speedLabel->setFont (Font (15.0000f, Font::plain));
    speedLabel->setJustificationType (Justification::centredLeft);
    speedLabel->setEditable (false, false, false);
    speedLabel->setColour (Label::textColourId, Colours::white);
    speedLabel->setColour (TextEditor::textColourId, Colours::black);
    speedLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (gainSlider = new Slider (T("new slider")));
    gainSlider->setRange (0, 1, 0.01);
    gainSlider->setSliderStyle (Slider::LinearVertical);
    gainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    gainSlider->addListener (this);

    addAndMakeVisible (sustainLabel = new Label (T("new label"),
                                                 T("gain")));
    sustainLabel->setFont (Font (15.0000f, Font::plain));
    sustainLabel->setJustificationType (Justification::centredLeft);
    sustainLabel->setEditable (false, false, false);
    sustainLabel->setColour (Label::textColourId, Colours::white);
    sustainLabel->setColour (TextEditor::textColourId, Colours::black);
    sustainLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (randToggleButton = new ToggleButton (T("new toggle button")));
    randToggleButton->setButtonText (T("rand params"));
    randToggleButton->addListener (this);
    randToggleButton->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (transpRangeSlider = new Slider (T("new slider")));
    transpRangeSlider->setRange (0, 1, 0.001);
    transpRangeSlider->setSliderStyle (Slider::LinearVertical);
    transpRangeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    transpRangeSlider->addListener (this);

    addAndMakeVisible (sustainLabel2 = new Label (T("new label"),
                                                  T("transp range +/-")));
    sustainLabel2->setFont (Font (15.0000f, Font::plain));
    sustainLabel2->setJustificationType (Justification::centredLeft);
    sustainLabel2->setEditable (false, false, false);
    sustainLabel2->setColour (Label::textColourId, Colours::white);
    sustainLabel2->setColour (TextEditor::textColourId, Colours::black);
    sustainLabel2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (transpRateSlider = new Slider (T("new slider")));
    transpRateSlider->setRange (0, 20, 1);
    transpRateSlider->setSliderStyle (Slider::LinearVertical);
    transpRateSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    transpRateSlider->addListener (this);

    addAndMakeVisible (sustainLabel3 = new Label (T("new label"),
                                                  T("sine transp rate (hz)")));
    sustainLabel3->setFont (Font (15.0000f, Font::plain));
    sustainLabel3->setJustificationType (Justification::centredLeft);
    sustainLabel3->setEditable (false, false, false);
    sustainLabel3->setColour (Label::textColourId, Colours::white);
    sustainLabel3->setColour (TextEditor::textColourId, Colours::black);
    sustainLabel3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (skipRateSlider = new Slider (T("new slider")));
    skipRateSlider->setRange (0, 10, 1);
    skipRateSlider->setSliderStyle (Slider::LinearVertical);
    skipRateSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    skipRateSlider->addListener (this);

    addAndMakeVisible (sustainLabel4 = new Label (T("new label"),
                                                  T("rand skip rate (hz)")));
    sustainLabel4->setFont (Font (15.0000f, Font::plain));
    sustainLabel4->setJustificationType (Justification::centredLeft);
    sustainLabel4->setEditable (false, false, false);
    sustainLabel4->setColour (Label::textColourId, Colours::white);
    sustainLabel4->setColour (TextEditor::textColourId, Colours::black);
    sustainLabel4->setColour (TextEditor::backgroundColourId, Colour (0x0));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (440, 340);

    //[Constructor] You can add your own custom stuff here..

	audioPlayer = new AudioPlayer();

	gainSlider->setValue(0.8);
	transpRateSlider->setValue(0);
	transpRangeSlider->setValue(0);
	skipRateSlider->setValue(4);

    //[/Constructor]
}

SamplerComponent::~SamplerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (fileButton);
    deleteAndZero (chooseLabel);
    deleteAndZero (speedSlider);
    deleteAndZero (speedLabel);
    deleteAndZero (gainSlider);
    deleteAndZero (sustainLabel);
    deleteAndZero (randToggleButton);
    deleteAndZero (transpRangeSlider);
    deleteAndZero (sustainLabel2);
    deleteAndZero (transpRateSlider);
    deleteAndZero (sustainLabel3);
    deleteAndZero (skipRateSlider);
    deleteAndZero (sustainLabel4);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SamplerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffb50000));

    g.setColour (Colour (0xff00d1ca));
    g.fillPath (internalPath1);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SamplerComponent::resized()
{
    fileButton->setBounds (8, 16, 56, 24);
    chooseLabel->setBounds (64, 16, 392, 24);
    speedSlider->setBounds (112, 88, 135, 72);
    speedLabel->setBounds (200, 64, 48, 24);
    gainSlider->setBounds (16, 80, 72, 72);
    sustainLabel->setBounds (56, 56, 48, 24);
    randToggleButton->setBounds (296, 120, 150, 24);
    transpRangeSlider->setBounds (24, 208, 72, 104);
    sustainLabel2->setBounds (16, 176, 128, 24);
    transpRateSlider->setBounds (160, 208, 72, 104);
    sustainLabel3->setBounds (144, 176, 128, 24);
    skipRateSlider->setBounds (296, 200, 72, 112);
    sustainLabel4->setBounds (280, 176, 128, 24);
    internalPath1.clear();
    internalPath1.startNewSubPath (16.0f, 160.0f);
    internalPath1.lineTo (288.0f, 160.0f);
    internalPath1.lineTo (288.0f, 112.0f);
    internalPath1.lineTo (424.0f, 112.0f);
    internalPath1.lineTo (424.0f, 320.0f);
    internalPath1.lineTo (12.0f, 318.0f);
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SamplerComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == fileButton)
    {
        //[UserButtonCode_fileButton] -- add your button handler code here..
		File audioFile;
		FileChooser chooser (T("Choose file to open"),File::nonexistent,"*",true);
		chooser.browseForFileToOpen();
		audioFile = chooser.getResult();

		// only start playing if audio file exists, otherwise it will crash
		if (audioFile.exists()) {
			audioPlayer->setFile(audioFile);
			audioPlayer->playSample();
			chooseLabel->setText(audioFile.getFullPathName(), true);
		}
        //[/UserButtonCode_fileButton]
    }
    else if (buttonThatWasClicked == randToggleButton)
    {
        //[UserButtonCode_randToggleButton] -- add your button handler code here..

		audioPlayer->setRandParam(randToggleButton->getToggleState());

        //[/UserButtonCode_randToggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void SamplerComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == speedSlider)
    {
        //[UserSliderCode_speedSlider] -- add your slider handling code here..
		double ratio;

		if (speedSlider->getValue() > -1 && speedSlider->getValue() < 1){
			ratio = 1.0;
		}
		else if (speedSlider->getValue() >= 1){
			ratio = (double) speedSlider->getValue();
			std::cout << "ratio: " << ratio << "\n";
		}
		else if (speedSlider->getValue() <= -1){
			ratio =  1/fabs((double)speedSlider->getValue());
			std::cout << "ratio: " << ratio << "\n";
		}

		audioPlayer->changeSpeed(ratio);

        //[/UserSliderCode_speedSlider]
    }
    else if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
			audioPlayer->changeGain(gainSlider->getValue());
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == transpRangeSlider)
    {
        //[UserSliderCode_transpRangeSlider] -- add your slider handling code here..
		audioPlayer->setTranspRange(transpRangeSlider->getValue());

        //[/UserSliderCode_transpRangeSlider]
    }
    else if (sliderThatWasMoved == transpRateSlider)
    {
        //[UserSliderCode_transpRateSlider] -- add your slider handling code here..
		audioPlayer->setTranspRate((int)transpRateSlider->getValue());
        //[/UserSliderCode_transpRateSlider]
    }
    else if (sliderThatWasMoved == skipRateSlider)
    {
        //[UserSliderCode_skipRateSlider] -- add your slider handling code here..
		audioPlayer->setSkipRate((int)skipRateSlider->getValue());
        //[/UserSliderCode_skipRateSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SamplerComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="440" initialHeight="340">
  <BACKGROUND backgroundColour="ffb50000">
    <PATH pos="0 0 100 100" fill="solid: ff00d1ca" hasStroke="0" nonZeroWinding="1">s 16 160 l 288 160 l 288 112 l 424 112 l 424 320 l 12 318 x</PATH>
  </BACKGROUND>
  <TEXTBUTTON name="new button" id="f900e0eb37fca2ee" memberName="fileButton"
              virtualName="" explicitFocusOrder="0" pos="8 16 56 24" bgColOff="fffdfdfd"
              buttonText="file" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="f5d0b856b9c1a548" memberName="chooseLabel"
         virtualName="" explicitFocusOrder="0" pos="64 16 392 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="choose file..."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="6c8e6ad8cc6bc03d" memberName="speedSlider"
          virtualName="" explicitFocusOrder="0" pos="112 88 135 72" rotarysliderfill="7f00ffff"
          min="-10" max="10" int="0.1" style="Rotary" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="3a2e160939b6a78a" memberName="speedLabel"
         virtualName="" explicitFocusOrder="0" pos="200 64 48 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="speed" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="e24a1fcacf8ba487" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="16 80 72 72" min="0"
          max="1" int="0.01" style="LinearVertical" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="14d18467a6f5f3c3" memberName="sustainLabel"
         virtualName="" explicitFocusOrder="0" pos="56 56 48 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="247df3d8e9f7311f" memberName="randToggleButton"
                virtualName="" explicitFocusOrder="0" pos="296 120 150 24" txtcol="ffffffff"
                buttonText="rand params" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="e0e52767144ed3a" memberName="transpRangeSlider"
          virtualName="" explicitFocusOrder="0" pos="24 208 72 104" min="0"
          max="1" int="0.001" style="LinearVertical" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="c80994b22b4f3800" memberName="sustainLabel2"
         virtualName="" explicitFocusOrder="0" pos="16 176 128 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="transp range +/-"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="371ba5a495a183e0" memberName="transpRateSlider"
          virtualName="" explicitFocusOrder="0" pos="160 208 72 104" min="0"
          max="20" int="1" style="LinearVertical" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="8c83d0496a64536c" memberName="sustainLabel3"
         virtualName="" explicitFocusOrder="0" pos="144 176 128 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="sine transp rate (hz)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="22e5dfe30dc60561" memberName="skipRateSlider"
          virtualName="" explicitFocusOrder="0" pos="296 200 72 112" min="0"
          max="10" int="1" style="LinearVertical" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="366147b8a12f27df" memberName="sustainLabel4"
         virtualName="" explicitFocusOrder="0" pos="280 176 128 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="rand skip rate (hz)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
