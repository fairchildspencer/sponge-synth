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
    
    void initializeSlider(juce::Slider& slider);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrUI)
};
