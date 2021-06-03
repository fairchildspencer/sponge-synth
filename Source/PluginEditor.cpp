
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpongeSynthAudioProcessorEditor::SpongeSynthAudioProcessorEditor (SpongeSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    
    using SliderClass = juce::AudioProcessorValueTreeState::SliderAttachment; //set the namespace for cleaner declarations
    
    attackAttachment = std::make_unique<SliderClass>(audioProcessor.apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<SliderClass>(audioProcessor.apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<SliderClass>(audioProcessor.apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<SliderClass>(audioProcessor.apvts, "RELEASE", releaseSlider);
    
    oscSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "OSC", oscSelector);
}

SpongeSynthAudioProcessorEditor::~SpongeSynthAudioProcessorEditor()
{
}

//==============================================================================
void SpongeSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("The Sponge Synth", getLocalBounds(), juce::Justification::centred, 1);
}

void SpongeSynthAudioProcessorEditor::resized()
{

}
