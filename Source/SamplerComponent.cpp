/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  4 Oct 2011 11:00:03am

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
      sustainLabel (0)
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
    speedSlider->setRange (-10, 10, 0.1);
    speedSlider->setSliderStyle (Slider::Rotary);
    speedSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    speedSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ffff));
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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (440, 340);


    //[Constructor] You can add your own custom stuff here..

	audioPlayer = new AudioPlayer();

	gainSlider->setValue(0.8);

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


    //[Destructor]. You can add your own custom destruction code here..
	deleteAndZero (audioPlayer);
    //[/Destructor]
}

//==============================================================================
void SamplerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffb50000));

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
  <BACKGROUND backgroundColour="ffb50000"/>
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
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
