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
      chopButton (0),
      chopSlider (0),
      chopLabel (0),
      chopRepeatProbSlider (0),
      chopRepeatProbLabel (0),
      chopAdvanceProbSlider (0),
      chopAdvanceProbLabel (0),
      waveformDisplayComponent (0)
{
    addAndMakeVisible (fileButton = new TextButton (L"new button"));
    fileButton->setButtonText (L"file");
    fileButton->addListener (this);
    fileButton->setColour (TextButton::buttonColourId, Colour (0xfffdfdfd));

    addAndMakeVisible (chooseLabel = new Label (L"new label",
                                                L"choose file..."));
    chooseLabel->setFont (Font (15.0000f, Font::plain));
    chooseLabel->setJustificationType (Justification::centredLeft);
    chooseLabel->setEditable (false, false, false);
    chooseLabel->setColour (Label::textColourId, Colours::white);
    chooseLabel->setColour (TextEditor::textColourId, Colours::black);
    chooseLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (speedSlider = new Slider (L"new slider"));
    speedSlider->setRange (0.1, 10, 0.01);
    speedSlider->setSliderStyle (Slider::Rotary);
    speedSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    speedSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    speedSlider->addListener (this);

    addAndMakeVisible (speedLabel = new Label (L"new label",
                                               L"speed"));
    speedLabel->setFont (Font (15.0000f, Font::plain));
    speedLabel->setJustificationType (Justification::centredLeft);
    speedLabel->setEditable (false, false, false);
    speedLabel->setColour (Label::textColourId, Colours::white);
    speedLabel->setColour (TextEditor::textColourId, Colours::black);
    speedLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (gainSlider = new Slider (L"new slider"));
    gainSlider->setRange (0, 1, 0.01);
    gainSlider->setSliderStyle (Slider::LinearVertical);
    gainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    gainSlider->addListener (this);

    addAndMakeVisible (sustainLabel = new Label (L"new label",
                                                 L"gain"));
    sustainLabel->setFont (Font (15.0000f, Font::plain));
    sustainLabel->setJustificationType (Justification::centredLeft);
    sustainLabel->setEditable (false, false, false);
    sustainLabel->setColour (Label::textColourId, Colours::white);
    sustainLabel->setColour (TextEditor::textColourId, Colours::black);
    sustainLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (chopButton = new ToggleButton (L"new toggle button"));
    chopButton->setButtonText (L"chop");
    chopButton->addListener (this);
    chopButton->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (chopSlider = new Slider (L"new slider"));
    chopSlider->setRange (0, 44100, 1);
    chopSlider->setSliderStyle (Slider::Rotary);
    chopSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chopSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    chopSlider->addListener (this);

    addAndMakeVisible (chopLabel = new Label (L"new label",
                                              L"chop length"));
    chopLabel->setFont (Font (15.0000f, Font::plain));
    chopLabel->setJustificationType (Justification::centredLeft);
    chopLabel->setEditable (false, false, false);
    chopLabel->setColour (Label::textColourId, Colours::white);
    chopLabel->setColour (TextEditor::textColourId, Colours::black);
    chopLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (chopRepeatProbSlider = new Slider (L"new slider"));
    chopRepeatProbSlider->setRange (0, 1, 0.01);
    chopRepeatProbSlider->setSliderStyle (Slider::Rotary);
    chopRepeatProbSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chopRepeatProbSlider->setColour (Slider::thumbColourId, Colours::white);
    chopRepeatProbSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    chopRepeatProbSlider->addListener (this);

    addAndMakeVisible (chopRepeatProbLabel = new Label (L"new label",
                                                        L"chop repeat probability"));
    chopRepeatProbLabel->setFont (Font (15.0000f, Font::plain));
    chopRepeatProbLabel->setJustificationType (Justification::centredLeft);
    chopRepeatProbLabel->setEditable (false, false, false);
    chopRepeatProbLabel->setColour (Label::textColourId, Colours::white);
    chopRepeatProbLabel->setColour (TextEditor::textColourId, Colours::black);
    chopRepeatProbLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (chopAdvanceProbSlider = new Slider (L"new slider"));
    chopAdvanceProbSlider->setRange (0, 1, 0.01);
    chopAdvanceProbSlider->setSliderStyle (Slider::Rotary);
    chopAdvanceProbSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chopAdvanceProbSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    chopAdvanceProbSlider->addListener (this);

    addAndMakeVisible (chopAdvanceProbLabel = new Label (L"new label",
                                                         L"chop advance probability"));
    chopAdvanceProbLabel->setFont (Font (15.0000f, Font::plain));
    chopAdvanceProbLabel->setJustificationType (Justification::centredLeft);
    chopAdvanceProbLabel->setEditable (false, false, false);
    chopAdvanceProbLabel->setColour (Label::textColourId, Colours::white);
    chopAdvanceProbLabel->setColour (TextEditor::textColourId, Colours::black);
    chopAdvanceProbLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (waveformDisplayComponent = new WaveformDisplayComponent());
    waveformDisplayComponent->setName (L"new component");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 500);


    //[Constructor] You can add your own custom stuff here..

	audioPlayer = new AudioPlayer();

	speedSlider->setValue(0.8);
	gainSlider->setValue(1.0);
	chopSlider->setValue(44100);
	chopRepeatProbSlider->setValue(0.2);
	chopAdvanceProbSlider->setValue(0.2);

	audioPlayer->setWaveformDisplayComponent(waveformDisplayComponent);
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
    deleteAndZero (chopButton);
    deleteAndZero (chopSlider);
    deleteAndZero (chopLabel);
    deleteAndZero (chopRepeatProbSlider);
    deleteAndZero (chopRepeatProbLabel);
    deleteAndZero (chopAdvanceProbSlider);
    deleteAndZero (chopAdvanceProbLabel);
    deleteAndZero (waveformDisplayComponent);


    //[Destructor]. You can add your own custom destruction code here..
	deleteAndZero (audioPlayer);
    //[/Destructor]
}

//==============================================================================
void SamplerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff590065));

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
    chopButton->setBounds (272, 112, 56, 24);
    chopSlider->setBounds (336, 88, 135, 72);
    chopLabel->setBounds (408, 64, 80, 24);
    chopRepeatProbSlider->setBounds (336, 184, 135, 72);
    chopRepeatProbLabel->setBounds (336, 160, 160, 32);
    chopAdvanceProbSlider->setBounds (112, 184, 135, 72);
    chopAdvanceProbLabel->setBounds (112, 160, 176, 32);
    waveformDisplayComponent->setBounds (16, 272, 464, 184);
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
    else if (buttonThatWasClicked == chopButton)
    {
        //[UserButtonCode_chopButton] -- add your button handler code here..
		audioPlayer->setChopEnable(buttonThatWasClicked->getToggleState());
        //[/UserButtonCode_chopButton]
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
		double ratio = speedSlider->getValue();

		audioPlayer->changeSpeed(ratio);
        //[/UserSliderCode_speedSlider]
    }
    else if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
		audioPlayer->changeGain(gainSlider->getValue());
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == chopSlider)
    {
        //[UserSliderCode_chopSlider] -- add your slider handling code here..
		audioPlayer->setChopAmount(chopSlider->getValue());
        //[/UserSliderCode_chopSlider]
    }
    else if (sliderThatWasMoved == chopRepeatProbSlider)
    {
        //[UserSliderCode_chopRepeatProbSlider] -- add your slider handling code here..
		audioPlayer->setChopRepeatProbability(chopRepeatProbSlider->getValue());
        //[/UserSliderCode_chopRepeatProbSlider]
    }
    else if (sliderThatWasMoved == chopAdvanceProbSlider)
    {
        //[UserSliderCode_chopAdvanceProbSlider] -- add your slider handling code here..
		audioPlayer->setChopAdvanceProbability(chopAdvanceProbSlider->getValue());
        //[/UserSliderCode_chopAdvanceProbSlider]
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
                 fixedSize="0" initialWidth="500" initialHeight="500">
  <BACKGROUND backgroundColour="ff590065"/>
  <TEXTBUTTON name="new button" id="f900e0eb37fca2ee" memberName="fileButton"
              virtualName="" explicitFocusOrder="0" pos="8 16 56 24" bgColOff="fffdfdfd"
              buttonText="file" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="f5d0b856b9c1a548" memberName="chooseLabel"
         virtualName="" explicitFocusOrder="0" pos="64 16 392 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="choose file..."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="6c8e6ad8cc6bc03d" memberName="speedSlider"
          virtualName="" explicitFocusOrder="0" pos="112 88 135 72" rotarysliderfill="7fffffff"
          min="0.1" max="10" int="0.01" style="Rotary" textBoxPos="TextBoxLeft"
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
  <TOGGLEBUTTON name="new toggle button" id="1e2a614fe6f24e01" memberName="chopButton"
                virtualName="" explicitFocusOrder="0" pos="272 112 56 24" txtcol="ffffffff"
                buttonText="chop" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <SLIDER name="new slider" id="5b4e236ccea8cf23" memberName="chopSlider"
          virtualName="" explicitFocusOrder="0" pos="336 88 135 72" rotarysliderfill="7fffffff"
          min="0" max="44100" int="1" style="Rotary" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="6203385805c32086" memberName="chopLabel"
         virtualName="" explicitFocusOrder="0" pos="408 64 80 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="chop length" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="82801c1b045e79c8" memberName="chopRepeatProbSlider"
          virtualName="" explicitFocusOrder="0" pos="336 184 135 72" thumbcol="ffffffff"
          rotarysliderfill="7fffffff" min="0" max="1" int="0.01" style="Rotary"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="2918814bf2adccf1" memberName="chopRepeatProbLabel"
         virtualName="" explicitFocusOrder="0" pos="336 160 160 32" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="chop repeat probability"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="5ea74985e5676575" memberName="chopAdvanceProbSlider"
          virtualName="" explicitFocusOrder="0" pos="112 184 135 72" rotarysliderfill="7fffffff"
          min="0" max="1" int="0.01" style="Rotary" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="639cdec0f057002d" memberName="chopAdvanceProbLabel"
         virtualName="" explicitFocusOrder="0" pos="112 160 176 32" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="chop advance probability"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="new component" id="13217c2a0549b206" memberName="waveformDisplayComponent"
                    virtualName="" explicitFocusOrder="0" pos="16 272 464 184" class="WaveformDisplayComponent"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
