/*
  ==============================================================================

    AdsrUI.h
    Created: 17 Jun 2021 1:12:19pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrUI  : public juce::Component
{
public:
    AdsrUI(juce::AudioProcessorValueTreeState& apvts);
    ~AdsrUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decayAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseAttachment;
    
    juce::Label attackLabel { "Attack", "A" };
    juce::Label decayLabel { "Decay", "D" };
    juce::Label sustainLabel { "Sustain", "S" };
    juce::Label releaseLabel { "Release", "R" };
    
    void initializeSlider(juce::Slider& slider);
    void initializeLabel(juce::Label& label);
    
    juce::String componentName {"Envelope"};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrUI)
};
