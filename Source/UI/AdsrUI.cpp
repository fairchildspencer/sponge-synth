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
}

AdsrUI::~AdsrUI() {
}

void AdsrUI::paint (juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void AdsrUI::resized() {
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = (bounds.getWidth() / 4) - padding;
    const auto sliderHeight = bounds.getHeight() - padding;
    const auto sliderStartX = 0;
    const auto sliderStartY = 0;
    
    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);

}

void AdsrUI::initializeSlider(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}
