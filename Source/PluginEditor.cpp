
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpongeSynthAudioProcessorEditor::SpongeSynthAudioProcessorEditor (SpongeSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc(audioProcessor.apvts, "OSC", "FMFREQUENCY", "FMDEPTH"), adsr(audioProcessor.apvts), filter(audioProcessor.apvts, "FILTERTYPE", "CUTOFF", "RESONANCE", "ONOFF"), reverb(audioProcessor.apvts, "ROOMSIZE", "DRY", "WET", "DAMPING", "WIDTH") {
    
    setSize (670, 450);

    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
    addAndMakeVisible(filter);
    addAndMakeVisible(reverb);
}

SpongeSynthAudioProcessorEditor::~SpongeSynthAudioProcessorEditor() {
}

//==============================================================================
void SpongeSynthAudioProcessorEditor::paint (juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void SpongeSynthAudioProcessorEditor::resized() {
    const auto paddingX = 10;
    const auto paddingY = 10;
    
    osc.setBounds (paddingX, paddingY, 300, 200);
    adsr.setBounds (osc.getRight(), paddingY, 340, 200);
    filter.setBounds (paddingX, osc.getBottom() + paddingY, 300, 200);
    reverb.setBounds(filter.getRight(), adsr.getBottom() + paddingY, 340, 200);
}
