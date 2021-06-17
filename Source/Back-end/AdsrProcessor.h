/*
  ==============================================================================

    AdsrProcessor.h
    Created: 17 Jun 2021 1:13:02pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrProcessor : public juce::ADSR {
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);
    
private:
    juce::ADSR::Parameters adsrParams;
};
