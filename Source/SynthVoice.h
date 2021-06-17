/*
  ==============================================================================

    SynthVoice.h
    Created: 20 Apr 2021 9:09:38pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "Back-end/AdsrProcessor.h"
#include "Back-end/OscillatorProcessor.h"

class SynthVoice : public juce::SynthesiserVoice {
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound,
                            int currentPitchWheelPosition) override;
    void stopNote (float velocity, bool allowTailOff) override;
    void pitchWheelMoved (int newPitchWheelValue) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock (juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override;
    
    void updateParameters(const float attack, const float decay, const float sustain, const float release);
    OscillatorProcessor& getOscillator() { return oscillator; }
    
private:
    OscillatorProcessor oscillator;
    
    juce::AudioBuffer<float> synthBuffer;
    
    AdsrProcessor adsr;
    
    juce::dsp::Gain<float> gain;
    
    bool isPrepared = false;
};

