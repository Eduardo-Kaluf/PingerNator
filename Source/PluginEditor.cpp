#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    // Connect the knob to the "LEVEL" parameter in the processor
    levelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        processorRef.apvts, "LEVEL", pingerKnob.getSlider());

    addAndMakeVisible (pingerKnob);

    setSize (600, 400);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
= default;

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setFont (juce::FontOptions (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("PingerNator", getWidth() / 2 - 100, 20, 200, 20, juce::Justification::centred, true);

    // You can now get the value directly from the knob or the parameter
    auto valueText = juce::String(pingerKnob.getValue(), 2);
    g.drawText (valueText, getWidth() / 2 - 100, 250, 200, 20, juce::Justification::centred, true);
}

void AudioPluginAudioProcessorEditor::resized()
{
    pingerKnob.setBounds (getWidth() / 2 - 100, 100, 200, 150);
}
