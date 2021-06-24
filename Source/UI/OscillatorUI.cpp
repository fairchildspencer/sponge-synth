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
OscillatorUI::OscillatorUI(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectID, juce::String fmFreqID,             juce::String fmDepthID) {
    juce::StringArray waveChoices {"Sine", "Saw", "Square"};
    oscWaveSelector.addItemList(waveChoices, 1);
    addAndMakeVisible(oscWaveSelector);
    
    oscWaveAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectID, oscWaveSelector);
    
    
    using SliderClass = juce::AudioProcessorValueTreeState::SliderAttachment; //set the namespace for cleaner declarations
    
    frequencyAttachment = std::make_unique<SliderClass>(apvts, fmFreqID, frequencySlider);
    depthAttachment = std::make_unique<SliderClass>(apvts, fmDepthID, depthSlider);

    initializeSlider(frequencySlider);
    initializeSlider(depthSlider);
    
    initializeLabel(frequencyLabel);
    initializeLabel(depthLabel);
}

OscillatorUI::~OscillatorUI() {
}

void OscillatorUI::paint (juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void OscillatorUI::resized() {
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelHeight = 20;
    const auto labelYOffset = 20;
    const auto sliderY = 80;
    
    oscWaveSelector.setBounds(0,0,100,20);
    frequencySlider.setBounds(0, sliderY, sliderWidth, sliderHeight);
    frequencyLabel.setBounds(frequencySlider.getX(), frequencySlider.getY() - labelYOffset, frequencySlider.getWidth(), labelHeight);
    
    depthSlider.setBounds(frequencySlider.getRight(), sliderY, sliderWidth, sliderHeight);
    depthLabel.setBounds(depthSlider.getX(), depthSlider.getY() - labelYOffset, depthSlider.getWidth(), labelHeight);
}

void OscillatorUI::initializeSlider(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}

void OscillatorUI::initializeLabel(juce::Label& label) {
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(15.0f);
    addAndMakeVisible(label);
}
