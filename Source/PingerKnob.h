#ifndef PINGERKNOB_H
#define PINGERKNOB_H

#pragma once

#include <JuceHeader.h>

class PingerKnob : public Component {
    public:
        PingerKnob (AudioProcessorValueTreeState& vts,
                        const String& paramID,
                        const String& displayName);

        ~PingerKnob() override;

        void resized() override;

    private:
        Slider slider;
        Label label;
        TextButton bypassButton;
        std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attachment;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PingerKnob)
};

#endif //PINGERKNOB_H
