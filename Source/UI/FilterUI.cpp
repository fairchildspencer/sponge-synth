/*
  ==============================================================================

    FilterUI.cpp
    Created: 28 Jun 2021 8:40:49pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterUI.h"

//==============================================================================
FilterUI::FilterUI(juce::AudioProcessorValueTreeState& apvts, juce::String filterSelectID, juce::String cutoffID,             juce::String resonanceID, juce::String onOffID) {
    
    juce::StringArray filterTypeChoices {"Low-pass", "Band-pass", "High-pass"};
    filterType.addItemList(filterTypeChoices, 1);
    addAndMakeVisible(filterType);
    
    filterTypeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, filterSelectID, filterType);
    
    
    using SliderClass = juce::AudioProcessorValueTreeState::SliderAttachment; //set the namespace for cleaner declarations
    
    cutoffAttachment = std::make_unique<SliderClass>(apvts, cutoffID, cutoffSlider);
    resonanceAttachment = std::make_unique<SliderClass>(apvts, resonanceID, resonanceSlider);

    initializeSlider(cutoffSlider);
    initializeSlider(resonanceSlider);
    
    initializeLabel(cutoffLabel);
    initializeLabel(resonanceLabel);
    
    filterTypeLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::white);
    filterTypeLabel.setFont (15.0f);
    filterTypeLabel.setJustificationType (juce::Justification::left);
    addAndMakeVisible (filterTypeLabel);
    
    onOffAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(apvts, onOffID, onOffButton);
    onOffButton.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    onOffLabel.setColour (juce::Label::ColourIds::textColourId, juce::Colours::white);
    onOffLabel.setFont (15.0f);
    addAndMakeVisible(onOffLabel);
    addAndMakeVisible(onOffButton);
}

FilterUI::~FilterUI() {
}

void FilterUI::paint (juce::Graphics& g) {
    auto bounds = getLocalBounds().reduced (5);
    auto labelSpace = bounds.removeFromTop (25.0f);
    
    g.fillAll(juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (20.0f);
    g.drawText ("Filter", labelSpace.withX (5), juce::Justification::left);
    g.drawRoundedRectangle (bounds.toFloat(), 5.0f, 2.0f);
}

void FilterUI::resized() {
    const auto startY = 55;
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
    
    onOffButton.setBounds(10, startY - 5, 20, 20);
    onOffLabel.setBounds(onOffButton.getRight() + 5, startY - 5, 60, labelHeight);
        
    filterTypeLabel.setBounds (10, onOffButton.getBottom() + 14, 90, labelHeight);
    filterType.setBounds (10, filterTypeLabel.getBottom() + 5, 90, 30);
        
    cutoffSlider.setBounds (filterType.getRight(), startY, sliderWidth, sliderHeight);
    cutoffLabel.setBounds (cutoffSlider.getX(), cutoffSlider.getY() - labelYOffset, cutoffSlider.getWidth(), labelHeight);

    resonanceSlider.setBounds (cutoffSlider.getRight(), startY, sliderWidth, sliderHeight);
    resonanceLabel.setBounds (resonanceSlider.getX(), resonanceSlider.getY() - labelYOffset, resonanceSlider.getWidth(), labelHeight);
}

void FilterUI::initializeSlider(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}

void FilterUI::initializeLabel(juce::Label& label) {
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(15.0f);
    addAndMakeVisible(label);
}
