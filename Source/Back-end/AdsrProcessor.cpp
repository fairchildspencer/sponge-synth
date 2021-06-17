/*
  ==============================================================================

    AdsrProcessor.cpp
    Created: 17 Jun 2021 1:13:02pm
    Author:  Spencer Fairchild

  ==============================================================================
*/

#include "AdsrProcessor.h"

void AdsrProcessor::updateADSR(const float attack, const float decay, const float sustain, const float release) {
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release; //in seconds
    
    setParameters(adsrParams);
}
