#pragma once
#include <JuceHeader.h>

#include "PingerKnob.h"
#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor : public AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    AudioPluginAudioProcessor& processorRef;

    PingerKnob saturationKnob;
    PingerKnob bitcrushKnob;
    PingerKnob distortionKnob;
    PingerKnob fuzzKnob;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};

