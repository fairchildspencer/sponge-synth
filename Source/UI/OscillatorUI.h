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
    OscillatorUI(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectID, juce::String fmFreqID, juce::String fmDepthID);
    ~OscillatorUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider frequencySlider;
    juce::Slider depthSlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> frequencyAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> depthAttachment;
   
    juce::Label frequencyLabel { "FM Frequency", "FM Frequency" };
    juce::Label depthLabel { "FM Depth", "FM Depth" };
    juce::Label waveSelectorLabel { "Wave Type", "Wave Type" };
    
    juce::ComboBox oscWaveSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveAttachment;
    
    void initializeSlider(juce::Slider& slider);
    void initializeLabel(juce::Label& label);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorUI)
};
