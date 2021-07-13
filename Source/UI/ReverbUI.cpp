/*
  ==============================================================================

    ReverbUI.cpp
    Created: 11 Jul 2021 6:13:00pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ReverbUI.h"

//==============================================================================
ReverbUI::ReverbUI(juce::AudioProcessorValueTreeState& apvts, juce::String roomSizeID, juce::String dryLevelID, juce::String wetLevelID, juce::String dampingID, juce::String widthID) {

    using SliderClass = juce::AudioProcessorValueTreeState::SliderAttachment; //set the namespace for cleaner declarations
    
    roomSizeAttachment = std::make_unique<SliderClass>(apvts, roomSizeID, roomSizeSlider);
    dryLevelAttachment = std::make_unique<SliderClass>(apvts, dryLevelID, dryLevelSlider);
    wetLevelAttachment = std::make_unique<SliderClass>(apvts, wetLevelID, wetLevelSlider);
    dampingAttachment = std::make_unique<SliderClass>(apvts, dampingID, dampingSlider);
    widthAttachment = std::make_unique<SliderClass>(apvts, widthID, widthSlider);

    initializeSlider(roomSizeSlider);
    initializeSlider(dryLevelSlider);
    initializeSlider(wetLevelSlider);
    initializeSlider(dampingSlider);
    initializeSlider(widthSlider);
    
    initializeLabel(roomSizeLabel);
    initializeLabel(dryLevelLabel);
    initializeLabel(wetLevelLabel);
    initializeLabel(dampingLabel);
    initializeLabel(widthLabel);
}

ReverbUI::~ReverbUI() {
}

void ReverbUI::paint (juce::Graphics& g) {
    auto bounds = getLocalBounds().reduced (5);
    auto labelSpace = bounds.removeFromTop (25.0f);
    
    g.fillAll(juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (20.0f);
    g.drawText ("Reverb", labelSpace.withX (5), juce::Justification::left);
    g.drawRoundedRectangle (bounds.toFloat(), 5.0f, 2.0f);
}

void ReverbUI::resized() {
    const auto bounds = getLocalBounds().reduced (10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() - 45;
    const auto sliderStartX = padding + 5;
    const auto sliderStartY = 55;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
    const auto labelStart = sliderStartY - labelYOffset;
    
    roomSizeSlider.setBounds (sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    roomSizeLabel.setBounds (roomSizeSlider.getX(), labelStart, sliderWidth, labelHeight);
    
    dryLevelSlider.setBounds (roomSizeSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    dryLevelLabel.setBounds (dryLevelSlider.getX(), labelStart, sliderWidth, labelHeight);
    
    wetLevelSlider.setBounds (dryLevelSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    wetLevelLabel.setBounds (wetLevelSlider.getX(), labelStart, sliderWidth, labelHeight);
    
    dampingSlider.setBounds (wetLevelSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    dampingLabel.setBounds (dampingSlider.getX(), labelStart, sliderWidth, labelHeight);
    
    widthSlider.setBounds (dampingSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    widthLabel.setBounds (widthSlider.getX(), labelStart, sliderWidth, labelHeight);
    
}

void ReverbUI::initializeSlider(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}

void ReverbUI::initializeLabel(juce::Label& label) {
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(15.0f);
    addAndMakeVisible(label);
}
