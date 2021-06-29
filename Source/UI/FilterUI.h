/*
  ==============================================================================

    FilterUI.h
    Created: 28 Jun 2021 8:40:49pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class FilterUI  : public juce::Component
{
public:
    FilterUI(juce::AudioProcessorValueTreeState& apvts, juce::String filterSelectID, juce::String cutoffID,             juce::String resonanceID);
    ~FilterUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider cutoffSlider;
    juce::Slider resonanceSlider;
    juce::ComboBox filterType { "Filter Type" };
    
    juce::Label cutoffLabel { "Cutoff", "Cutoff" };
    juce::Label resonanceLabel { "Resonance", "Resonance" };
    juce::Label filterTypeLabel { "Filter Type", "Filter Type" };
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutoffAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> resonanceAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeAttachment;
    
    void initializeSlider(juce::Slider& slider);
    void initializeLabel(juce::Label& label);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterUI)
};
