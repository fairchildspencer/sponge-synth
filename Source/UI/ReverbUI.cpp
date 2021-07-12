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

}

ReverbUI::~ReverbUI() {
}

void ReverbUI::paint (juce::Graphics& g) {

}

void ReverbUI::resized() {

}

void ReverbUI::initializeSlider(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}

void ReverbUI::initializeLabel(juce::Label& label) {
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(15.0f);
    addAndMakeVisible(label);
}
