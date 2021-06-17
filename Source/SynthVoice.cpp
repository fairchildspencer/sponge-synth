/*
  ==============================================================================

    SynthVoice.cpp
    Created: 20 Apr 2021 9:09:38pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound) {
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void SynthVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) {
    osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    adsr.noteOn();
}

void SynthVoice::stopNote (float velocity, bool allowTailOff) {
    adsr.noteOff();
    
    if (!allowTailOff || !adsr.isActive()) clearCurrentNote();
}

void SynthVoice::pitchWheelMoved (int newPitchWheelValue) {
    
}

void SynthVoice::controllerMoved (int controllerNumber, int newControllerValue) {
    
}

void SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels) {
    adsr.setSampleRate(sampleRate);
    
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    
    osc.prepare(spec);
    gain.prepare(spec);
    
    gain.setGainLinear(0.1f);
    
    adsrParams.attack = 0.8f;
    adsrParams.decay = 0.8f;
    adsrParams.sustain = 1.0f;
    adsrParams.release = 0.75f; //in seconds
    
    adsr.setParameters(adsrParams);
    
    isPrepared = true;
}

void SynthVoice::renderNextBlock (juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples) {
    jassert(isPrepared);
    
    if (!isVoiceActive()) return; //if the voice isn't playing don't do anything
    
    synthBuffer.setSize(outputBuffer.getNumChannels(), numSamples, false, false, true);
    synthBuffer.clear();
    
    juce::dsp::AudioBlock<float> audioBlock {synthBuffer};
    osc.process(juce::dsp::ProcessContextReplacing<float> (audioBlock));
    gain.process(juce::dsp::ProcessContextReplacing<float> (audioBlock));
    
    adsr.applyEnvelopeToBuffer(synthBuffer, 0, synthBuffer.getNumSamples());
    
    for (int i = 0; i < outputBuffer.getNumChannels(); ++i) {
        outputBuffer.addFrom(i, startSample, synthBuffer, i, 0, numSamples); //add the synth buffer to master output
        
        if(!adsr.isActive()) clearCurrentNote(); //if the note finishing while processing clear it
    }
}
