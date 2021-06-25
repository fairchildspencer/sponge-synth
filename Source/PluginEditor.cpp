
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpongeSynthAudioProcessorEditor::SpongeSynthAudioProcessorEditor (SpongeSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc(audioProcessor.apvts, "OSC", "FMFREQUENCY", "FMDEPTH"), adsr(audioProcessor.apvts) {
    setSize (620, 300);

    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
}

SpongeSynthAudioProcessorEditor::~SpongeSynthAudioProcessorEditor() {
}

//==============================================================================
void SpongeSynthAudioProcessorEditor::paint (juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void SpongeSynthAudioProcessorEditor::resized() {
    const auto paddingX = 5;
    //const auto paddingY = 35;
    
    osc.setBounds (paddingX, 0, 300, 200);
    adsr.setBounds (osc.getRight(), 0, 300, 200);
}
