/*
  ==============================================================================

    FilterProcessor.cpp
    Created: 28 Jun 2021 8:05:06pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include "FilterProcessor.h"

void FilterProcessor::prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels) {
    reset();
    
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = numChannels;
    
    filter.prepare(spec);
}

void FilterProcessor::process(juce::AudioBuffer<float>& buffer) {
    juce::dsp::AudioBlock<float> audioBlock { buffer };
    
    filter.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}

void FilterProcessor::updateParameters(const int filterType, const float cutoffFrequency, const float resonance) {
    switch (filterType) {
    case 0:
        filter.setType(juce::dsp::StateVariableTPTFilterType::lowpass);
        break;
    case 1:
        filter.setType(juce::dsp::StateVariableTPTFilterType::bandpass);
        break;
    case 2:
        filter.setType(juce::dsp::StateVariableTPTFilterType::highpass);
        break;
    }
    
    filter.setCutoffFrequency(cutoffFrequency);
    filter.setResonance(resonance);
}

void FilterProcessor::reset() {
    filter.reset();
}
