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
    fmOscillator.prepare(spec);
    prepare(spec);
}

void OscillatorProcessor::setWaveFrequency(const int midiNoteNumber) {
    lastMidiNote = midiNoteNumber;
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + fmModulation);
}

void OscillatorProcessor::getNextAudioBlock(juce::dsp::AudioBlock<float>& audioBlock) {
    
    for (int i = 0; i < audioBlock.getNumChannels(); i++) {
        for (int j = 0; j < audioBlock.getNumSamples(); j++) {
            fmModulation = fmOscillator.processSample(audioBlock.getSample(i, j)) * fmDepth;
        }
    }
    
    process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}

void OscillatorProcessor::setFMParams (const float depth, const float frequency) {
    fmOscillator.setFrequency(frequency);
    fmDepth = depth;
    
    // Need to reset the oscilattor frequency every time the parameter changes not just when a new note is played
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + fmModulation);
}
