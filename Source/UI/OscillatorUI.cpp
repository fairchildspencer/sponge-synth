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
    
    waveSelectorLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::white);
    waveSelectorLabel.setFont (15.0f);
    waveSelectorLabel.setJustificationType (juce::Justification::left);
    addAndMakeVisible (waveSelectorLabel);
}

OscillatorUI::~OscillatorUI() {
}

void OscillatorUI::paint (juce::Graphics& g) {
    auto bounds = getLocalBounds().reduced (5);
    auto labelSpace = bounds.removeFromTop (25.0f);
    
    g.fillAll(juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (20.0f);
    g.drawText ("Oscillator", labelSpace.withX (5), juce::Justification::left);
    g.drawRoundedRectangle (bounds.toFloat(), 5.0f, 2.0f);
}

void OscillatorUI::resized() {
    const auto startY = 55;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
        
    oscWaveSelector.setBounds (10, startY + 5, 90, 30);
    waveSelectorLabel.setBounds (10, startY - labelYOffset, 90, labelHeight);
        
    frequencySlider.setBounds (oscWaveSelector.getRight(), startY, sliderWidth, sliderHeight);
    frequencyLabel.setBounds (frequencySlider.getX(), frequencySlider.getY() - labelYOffset, frequencySlider.getWidth(), labelHeight);

    depthSlider.setBounds (frequencySlider.getRight(), startY, sliderWidth, sliderHeight);
    depthLabel.setBounds (depthSlider.getX(), depthSlider.getY() - labelYOffset, depthSlider.getWidth(), labelHeight);
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
