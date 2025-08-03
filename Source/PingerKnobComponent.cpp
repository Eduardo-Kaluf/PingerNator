#include "PingerKnobComponent.h"

PingerKnobComponent::PingerKnobComponent()
{
    knob.setRange (0, 100);
    knob.setTextValueSuffix (" PL");
    knob.setSliderStyle (juce::Slider::Rotary);
    knob.addListener (this);
    addAndMakeVisible (knob);

    label.setText ("Pinger Level", juce::dontSendNotification);
    label.attachToComponent (&knob, true);
    addAndMakeVisible (label);
}

void PingerKnobComponent::resized()
{
    knob.setBounds (getLocalBounds());
}

// Private listener callback for the internal slider
void PingerKnobComponent::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &knob)
    {
        // Notify any listeners (e.g., MainComponent) that our value has changed.
        listeners.call ([this] (Listener& l) { l.pingerKnobValueChanged (this); });
    }
}

// Public methods for parent components
void PingerKnobComponent::addListener (Listener* listenerToAdd)
{
    listeners.add (listenerToAdd);
}

void PingerKnobComponent::removeListener (Listener* listenerToRemove)
{
    listeners.remove (listenerToRemove);
}

double PingerKnobComponent::getValue() const
{
    return knob.getValue();
}