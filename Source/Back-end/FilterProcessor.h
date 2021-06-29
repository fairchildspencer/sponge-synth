/*
  ==============================================================================

    FilterProcessor.h
    Created: 28 Jun 2021 8:05:06pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class FilterProcessor {
public:
    void prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels);
    void process(juce::AudioBuffer<float>& buffer);
    void updateParameters(const int filterType, const float cutoffFrequency, const float resonance); //filter type is an enum
    void reset();
    
private:
    juce::dsp::StateVariableTPTFilter<float> filter;
};
