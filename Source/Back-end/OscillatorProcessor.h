/*
  ==============================================================================

    OscillatorProcessor.h
    Created: 17 Jun 2021 4:12:20pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class OscillatorProcessor : public juce::dsp::Oscillator<float> {
public:
    void setWaveType(const int waveType);
    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    void setWaveFrequency(const int midiNoteNumber);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& audioBlock);
    
private:
    
};
