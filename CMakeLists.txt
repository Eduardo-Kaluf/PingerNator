cmake_minimum_required(VERSION 3.22)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(PingerNator VERSION 0.0.1)

add_subdirectory(JUCE)

juce_add_plugin(PingerNator
    VERSION                     1.0.0
    ICON_BIG                    ./assets/pinger.png
    ICON_SMALL                  ./assets/pinger.png
    COMPANY_NAME                "KALUF"
    BUNDLE_ID                   "com.kaluf.PingerNator"
    IS_SYNTH                    FALSE
    NEEDS_MIDI_INPUT            FALSE
    NEEDS_MIDI_OUTPUT           FALSE
    IS_MIDI_EFFECT              FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD     FALSE
    PLUGIN_MANUFACTURER_CODE    Kalu
    PLUGIN_CODE                 Kaka
    FORMATS VST3                Standalone
    PRODUCT_NAME                "PingerNator")

juce_generate_juce_header(PingerNator)

target_sources(PingerNator
    PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginEditor.cpp
        Source/PingerKnob.cpp)

target_compile_definitions(PingerNator
    PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(PingerNator
    PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
