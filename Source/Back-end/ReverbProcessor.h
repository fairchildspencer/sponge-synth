/*
  ==============================================================================

    ReverbProcessor.h
    Created: 11 Jul 2021 5:38:34pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ReverbProcessor {
public:
    void prepare(double sampleRate, int samplesPerBlock, int numChannels);
    void process(juce::AudioBuffer<float>& buffer);
    void updateParams(const float roomSize, const float damping, const float wetLevel, const float dryLevel, const float width);
    
private:
    juce::dsp::Reverb reverb;
};
