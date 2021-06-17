/*
  ==============================================================================

    OscillatorUI.cpp
    Created: 17 Jun 2021 4:41:15pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscillatorUI.h"

//==============================================================================
OscillatorUI::OscillatorUI(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectID) {
    juce::StringArray waveChoices {"Sine", "Saw", "Square"};
    oscWaveSelector.addItemList(waveChoices, 1);
    addAndMakeVisible(oscWaveSelector);
    
    oscWaveAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectID, oscWaveSelector);
}

OscillatorUI::~OscillatorUI() {
}

void OscillatorUI::paint (juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void OscillatorUI::resized() {
    oscWaveSelector.setBounds(0,0,98,20);

}
