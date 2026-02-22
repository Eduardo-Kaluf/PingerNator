#include "PluginProcessor.h"
#include "PluginEditor.h"

#define SLIDER_X 256
#define SLIDER_Y 256

#define cornerLeftX  getWidth()  / 4 - SLIDER_X / 2
#define cornerRightX getWidth()  / 4 * 3 - SLIDER_X / 2
#define cornerLeftY  getHeight() / 4 - SLIDER_Y / 2
#define cornerRightY getHeight() / 4 * 3 - SLIDER_Y / 2

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p),
      processorRef(p),
      saturationKnob (p.apvts, "SATURATION", "Saturation"),
      bitcrushKnob   (p.apvts, "BIT_CRUSH",  "Bitcrush"),
      distortionKnob (p.apvts, "DISTORTION", "Distortion"),
      fuzzKnob       (p.apvts, "FUZZ",       "Fuzz")
{
    addAndMakeVisible(saturationKnob);
    addAndMakeVisible(bitcrushKnob);
    addAndMakeVisible(distortionKnob);
    addAndMakeVisible(fuzzKnob);

    setSize(512, 512);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() = default;

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setFont (FontOptions (16.0f));
    g.setColour (Colours::white);
}

void AudioPluginAudioProcessorEditor::resized()
{
    saturationKnob.setBounds(cornerLeftX, cornerLeftY, 256, 256);
    bitcrushKnob.setBounds(cornerLeftX, cornerRightY, 256, 256);
    distortionKnob.setBounds(cornerRightX, cornerLeftY, 256, 256);
    fuzzKnob.setBounds(cornerRightX, cornerRightY, 256, 256);
}
