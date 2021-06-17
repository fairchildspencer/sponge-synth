
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpongeSynthAudioProcessorEditor::SpongeSynthAudioProcessorEditor (SpongeSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc(audioProcessor.apvts, "OSC"), adsr(audioProcessor.apvts) {
    setSize (400, 300);

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
    osc.setBounds(10, 10, 100, 30);
    adsr.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}
