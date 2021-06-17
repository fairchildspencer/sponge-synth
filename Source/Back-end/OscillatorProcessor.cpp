/*
  ==============================================================================

    OscillatorProcessor.cpp
    Created: 17 Jun 2021 4:12:20pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include "OscillatorProcessor.h"

void OscillatorProcessor::setWaveType(const int waveType) {    
    switch (waveType) {
        case 0:
            initialise([](float x) { return std::sin(x); }); //sine wave
            break;
        case 1:
            initialise([](float x) { return x / juce::MathConstants<float>::pi; }); //saw wave
            break;
        case 2:
            initialise([](float x) { return x < 0.0f ? -1.0f : 1.0f; }); //square wave
            break;
        default:
            jassertfalse;
            break;
    }
}

void OscillatorProcessor::prepareToPlay(juce::dsp::ProcessSpec& spec) {
    prepare(spec);
}

void OscillatorProcessor::getNextAudioBlock(juce::dsp::AudioBlock<float>& audioBlock) {
    process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}

void OscillatorProcessor::setWaveFrequency(const int midiNoteNumber) {
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}
