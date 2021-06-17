
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrUI.h"

//==============================================================================
/**
*/
class SpongeSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SpongeSynthAudioProcessorEditor (SpongeSynthAudioProcessor&);
    ~SpongeSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SpongeSynthAudioProcessor& audioProcessor;
    AdsrUI adsr;
    
    juce::ComboBox oscSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelectAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpongeSynthAudioProcessorEditor)
};
