
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrUI.h"
#include "UI/OscillatorUI.h"
#include "UI/FilterUI.h"
#include "UI/ReverbUI.h"

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
    OscillatorUI osc;
    AdsrUI adsr;
    FilterUI filter;
    ReverbUI reverb;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpongeSynthAudioProcessorEditor)
};
