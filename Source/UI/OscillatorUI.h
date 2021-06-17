/*
  ==============================================================================

    OscillatorUI.h
    Created: 17 Jun 2021 4:41:15pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class OscillatorUI  : public juce::Component
{
public:
    OscillatorUI(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectID);
    ~OscillatorUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox oscWaveSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorUI)
};
