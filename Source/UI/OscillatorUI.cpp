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
    
    
    using SliderClass = juce::AudioProcessorValueTreeState::SliderAttachment; //set the namespace for cleaner declarations
    
    frequencyAttachment = std::make_unique<SliderClass>(apvts, "FMFREQUENCY", frequencySlider);
    depthAttachment = std::make_unique<SliderClass>(apvts, "FMDEPTH", depthSlider);

    initializeSlider(frequencySlider);
    initializeSlider(depthSlider);
}

OscillatorUI::~OscillatorUI() {
}

void OscillatorUI::paint (juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void OscillatorUI::resized() {
    oscWaveSelector.setBounds(0,0,98,20);
    
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderHeight = bounds.getHeight() / 3;
    const auto sliderWidth = bounds.getWidth() / 2 - padding;
    
    frequencySlider.setBounds(0, oscWaveSelector.getHeight() + padding, sliderWidth, sliderHeight);
    depthSlider.setBounds(frequencySlider.getRight() + padding, oscWaveSelector.getHeight() + padding, sliderWidth, sliderHeight);

}

void OscillatorUI::initializeSlider(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setRotaryParameters(0, juce::MathConstants<float>::pi, true);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}
