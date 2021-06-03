/*
  ==============================================================================

    SynthSound.h
    Created: 21 Apr 2021 3:30:25pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
    
public:
    
    bool appliesToNote(int midiNoteNumber) override {
        return true;
    }
    
    bool appliesToChannel(int midiChannel) override {
        return true;
    }
    
private:
    
};
