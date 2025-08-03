#pragma once

#include <JuceHeader.h>

class PingerKnobComponent final : public juce::Component,
                                  private juce::Slider::Listener
{
public:
    //==============================================================================
    // Listener class for parent components to receive callbacks
    class Listener {
        public:
            virtual ~Listener() = default;
            virtual void pingerKnobValueChanged (PingerKnobComponent* knob) = 0;
    };
    
    //==============================================================================
    // Contructor
    PingerKnobComponent();

    void resized() override;
    
    void addListener (Listener* listenerToAdd);
    void removeListener (Listener* listenerToRemove);
    
    double getValue() const;
    juce::Slider& getSlider() { return knob; }
private:
    //==============================================================================
    // This is the private listener for our internal slider
    void sliderValueChanged (juce::Slider* slider) override;
    
    juce::Slider knob;
    juce::Label label;

    juce::ListenerList<Listener> listeners;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PingerKnobComponent)
};
