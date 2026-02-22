//
// Created by kaluf on 22/02/26.
//

#include "PingerKnob.h"

PingerKnob::PingerKnob (AudioProcessorValueTreeState& vts,
                        const String& paramID,
                        const String& displayName)  {

    slider.setSliderStyle(Slider::Rotary);
    slider.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 30);
    slider.setRange(0.0f, 32.0f, 1.0f);
    addAndMakeVisible(slider);

    bypassButton.setButtonText("Bypass");
    bypassButton.setToggleState(false, dontSendNotification);
    bypassButton.setClickingTogglesState(true);
    addAndMakeVisible(bypassButton);

    label.setText (displayName, dontSendNotification);
    label.setJustificationType (Justification::centred);
    addAndMakeVisible (label);

    attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(vts, paramID, slider);
};

PingerKnob::~PingerKnob() = default;

void PingerKnob::resized() {
    auto area = getLocalBounds();
    label.setBounds (area.removeFromTop (20));
    bypassButton.setBounds (area.removeFromBottom (25).reduced(5));
    slider.setBounds (area);
}

