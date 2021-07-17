/*
  ==============================================================================

    AdsrUI.cpp
    Created: 17 Jun 2021 1:12:19pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrUI.h"

//==============================================================================
AdsrUI::AdsrUI(juce::AudioProcessorValueTreeState& apvts) {
    using SliderClass = juce::AudioProcessorValueTreeState::SliderAttachment; //set the namespace for cleaner declarations
    
    attackAttachment = std::make_unique<SliderClass>(apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<SliderClass>(apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<SliderClass>(apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<SliderClass>(apvts, "RELEASE", releaseSlider);

    initializeSlider(attackSlider);
    initializeSlider(decaySlider);
    initializeSlider(sustainSlider);
    initializeSlider(releaseSlider);
    
    initializeLabel(attackLabel);
    initializeLabel(decayLabel);
    initializeLabel(sustainLabel);
    initializeLabel(releaseLabel);
}

AdsrUI::~AdsrUI() {
}

void AdsrUI::paint (juce::Graphics& g) {
    auto bounds = getLocalBounds().reduced (5);
    auto labelSpace = bounds.removeFromTop (25.0f);
        
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (20.0f);
    g.drawText (componentName, labelSpace.withX (5), juce::Justification::left);
    g.drawRoundedRectangle (bounds.toFloat(), 5.0f, 2.0f);
}

void AdsrUI::resized() {
    const auto bounds = getLocalBounds().reduced (10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() - 45;
    const auto sliderStartX = padding + 5;
    const auto sliderStartY = 55;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
    const auto labelStart = sliderStartY - labelYOffset;
    
    attackSlider.setBounds (sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    attackLabel.setBounds (attackSlider.getX(), labelStart, sliderWidth, labelHeight);
    
    decaySlider.setBounds (attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    decayLabel.setBounds (decaySlider.getX(), labelStart, sliderWidth, labelHeight);
    
    sustainSlider.setBounds (decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainLabel.setBounds (sustainSlider.getX(), labelStart, sliderWidth, labelHeight);
    
    releaseSlider.setBounds (sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseLabel.setBounds (releaseSlider.getX(), labelStart, sliderWidth, labelHeight);
}

void AdsrUI::initializeSlider(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(slider);
}

void AdsrUI::initializeLabel(juce::Label& label) {
    label.setColour (juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setFont (15.0f);
    label.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (label);
}
