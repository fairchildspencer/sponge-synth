/*
  ==============================================================================

    ReverbProcessor.cpp
    Created: 11 Jul 2021 5:38:34pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include "ReverbProcessor.h"

void ReverbProcessor::prepare(double sampleRate, int samplesPerBlock, int numChannels) {
    reverb.reset();
    
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = numChannels;
    
    reverb.prepare(spec);
}

void ReverbProcessor::process(juce::AudioBuffer<float>& buffer) {
    juce::dsp::AudioBlock<float> audioBlock { buffer };
    
    reverb.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}

void ReverbProcessor::updateParams(const float roomSize, const float damping, const float wetLevel, const float dryLevel, const float width) {
    juce::dsp::Reverb::Parameters params;
    params.roomSize = roomSize;
    params.damping = damping;
    params.wetLevel = wetLevel;
    params.dryLevel = dryLevel;
    params.width = width;
    
    reverb.setParameters(params);
}
