
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SpongeSynthAudioProcessor::SpongeSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), apvts(*this, nullptr, "Parameters", createParams())
#endif
{
    synth.addSound(new SynthSound());
    synth.addVoice(new SynthVoice());
}

SpongeSynthAudioProcessor::~SpongeSynthAudioProcessor() {
}

//==============================================================================
const juce::String SpongeSynthAudioProcessor::getName() const {
    return JucePlugin_Name;
}

bool SpongeSynthAudioProcessor::acceptsMidi() const {
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SpongeSynthAudioProcessor::producesMidi() const {
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SpongeSynthAudioProcessor::isMidiEffect() const {
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SpongeSynthAudioProcessor::getTailLengthSeconds() const {
    return 0.0;
}

int SpongeSynthAudioProcessor::getNumPrograms() {
    return 1;
}

int SpongeSynthAudioProcessor::getCurrentProgram() {
    return 0;
}

void SpongeSynthAudioProcessor::setCurrentProgram (int index) {
}

const juce::String SpongeSynthAudioProcessor::getProgramName (int index) {
    return {};
}

void SpongeSynthAudioProcessor::changeProgramName (int index, const juce::String& newName) {
}

//==============================================================================
void SpongeSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {
    synth.setCurrentPlaybackSampleRate(sampleRate);
    
    for (int i = 0; i < synth.getNumVoices(); i++) {
        if (auto voice = dynamic_cast<SynthVoice*>(synth.getVoice(i))) {
            voice->prepareToPlay(sampleRate, samplesPerBlock, getTotalNumOutputChannels());
        }
    }
}

void SpongeSynthAudioProcessor::releaseResources() {
    
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SpongeSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const {
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SpongeSynthAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    for (int i = 0; i < synth.getNumVoices(); i++) {
        if (auto voice = dynamic_cast<SynthVoice*>(synth.getVoice(i))) {
            //lfo
            
            auto& attack = *apvts.getRawParameterValue("ATTACK");
            auto& decay = *apvts.getRawParameterValue("DECAY");
            auto& sustain = *apvts.getRawParameterValue("SUSTAIN");
            auto& release = *apvts.getRawParameterValue("RELEASE");
            
            auto& oscWave = *apvts.getRawParameterValue("OSC");
            
            auto& fmDepth = *apvts.getRawParameterValue("FMDEPTH");
            auto& fmFrequency = *apvts.getRawParameterValue("FMFREQUENCY");
            
            voice->getOscillator().setWaveType(oscWave);
            voice->getOscillator().setFMParams(fmDepth, fmFrequency);
            voice->updateParameters(attack, decay, sustain, release); //Update params with current value tree state
        }
    }

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool SpongeSynthAudioProcessor::hasEditor() const {
    return true;
}

juce::AudioProcessorEditor* SpongeSynthAudioProcessor::createEditor() {
    return new SpongeSynthAudioProcessorEditor (*this);
}

//==============================================================================
void SpongeSynthAudioProcessor::getStateInformation (juce::MemoryBlock& destData) {
    
}

void SpongeSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes) {

}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new SpongeSynthAudioProcessor();
}

juce::AudioProcessorValueTreeState::ParameterLayout SpongeSynthAudioProcessor::createParams() {
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    
    //ComboBox -Switch Oscillators
    params.push_back(std::make_unique<juce::AudioParameterChoice>("OSC", "Oscillator", juce::StringArray {"Sine","Saw","Square"}, 0));
    
    //FM - Frequency and Depth of Wave
    params.push_back(std::make_unique<juce::AudioParameterFloat>("FMFREQUENCY", "FmFrequency", juce::NormalisableRange<float> { 0.0f, 1000.0f, }, 5.0f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("FMDEPTH", "FmDepth", juce::NormalisableRange<float> { 0.0f, 1000.0f, }, 500.0f));
    
    //Attack -float
    params.push_back(std::make_unique<juce::AudioParameterFloat>("ATTACK", "Attack", juce::NormalisableRange<float> { 0.1f, 1.0f, }, 0.1f));
    //Decay -float
    params.push_back(std::make_unique<juce::AudioParameterFloat>("DECAY", "Decay", juce::NormalisableRange<float> { 0.1f, 1.0f, }, 0.1f));
    //Sustain -float
    params.push_back(std::make_unique<juce::AudioParameterFloat>("SUSTAIN", "Sustain", juce::NormalisableRange<float> { 0.1f, 1.0f, }, 1.0f));
    //Release -float
    params.push_back(std::make_unique<juce::AudioParameterFloat>("RELEASE", "Release", juce::NormalisableRange<float> { 0.1f, 3.0f, }, 0.4f));
    
    return {params.begin(), params.end()};
}

