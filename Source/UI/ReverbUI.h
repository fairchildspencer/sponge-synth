/*
  ==============================================================================

    ReverbUI.h
    Created: 11 Jul 2021 6:13:00pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ReverbUI  : public juce::Component
{
public:
    ReverbUI(juce::AudioProcessorValueTreeState& apvts, juce::String roomSizeID, juce::String dryLevelID, juce::String wetLevelID, juce::String dampingID, juce::String widthID);
    ~ReverbUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbUI)
    
    juce::Slider roomSizeSlider;
    juce::Slider dryLevelSlider;
    juce::Slider wetLevelSlider;
    juce::Slider dampingSlider;
    juce::Slider widthSlider;
    
    juce::Label roomSizeLabel { "Size", "Size" };
    juce::Label dryLevelLabel { "Dry", "Dry" };
    juce::Label wetLevelLabel { "Wet", "Wet" };
    juce::Label dampingLabel { "Damping", "Damping" };
    juce::Label widthLabel { "Width", "Width" };
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> roomSizeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dryLevelAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> wetLevelAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dampingAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> widthAttachment;
    
    void initializeSlider(juce::Slider& slider);
    void initializeLabel(juce::Label& label);
};
