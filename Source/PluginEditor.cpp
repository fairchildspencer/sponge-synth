
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpongeSynthAudioProcessorEditor::SpongeSynthAudioProcessorEditor (SpongeSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), adsr(audioProcessor.apvts) {
    setSize (400, 300);
    
    oscSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "OSC", oscSelector);

    addAndMakeVisible(adsr);
}

SpongeSynthAudioProcessorEditor::~SpongeSynthAudioProcessorEditor() {
}

//==============================================================================
void SpongeSynthAudioProcessorEditor::paint (juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void SpongeSynthAudioProcessorEditor::resized() {
    adsr.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}
