
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpongeSynthAudioProcessorEditor::SpongeSynthAudioProcessorEditor (SpongeSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc(audioProcessor.apvts, "OSC", "FMFREQUENCY", "FMDEPTH"), adsr(audioProcessor.apvts), filter(audioProcessor.apvts, "FILTERTYPE", "CUTOFF", "RESONANCE") {
    setSize (620, 500);

    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
    addAndMakeVisible(filter);
}

SpongeSynthAudioProcessorEditor::~SpongeSynthAudioProcessorEditor() {
}

//==============================================================================
void SpongeSynthAudioProcessorEditor::paint (juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void SpongeSynthAudioProcessorEditor::resized() {
    const auto paddingX = 5;
    const auto paddingY = 10;
    
    osc.setBounds (paddingX, paddingY, 300, 200);
    adsr.setBounds (osc.getRight(), paddingY, 300, 200);
    filter.setBounds (paddingX, osc.getBottom() + paddingY, 300, 200);
}
