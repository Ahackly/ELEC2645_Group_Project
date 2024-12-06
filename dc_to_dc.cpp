#include <iostream>
#include "dc_to_dc.h"

BuckConverter::BuckConverter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple) {
    _switching_frequency = switching_frequency;
    _input_voltage = input_voltage;
    _output_voltage = output_voltage;
    _current_ripple = current_ripple;
    _voltage_ripple = voltage_ripple;
}

float BuckConverter::calculate_duty_ratio() {
    if (_input_voltage == 0) {
        std::cerr << "Error: Input voltage cannot be zero for duty ratio calculation.\n";
        return 0.0f; // Indicate failure
    }

    // If parameters are valid, calculate and return duty ratio
    return _output_voltage / _input_voltage;
}

float BuckConverter::calculate_inductor_value() {
    float duty_ratio = calculate_duty_ratio();
    if (duty_ratio == 0) {
        std::cerr << "Error: Duty ratio calculation failed.\n";
        return 0.0f;
    }
    if (_switching_frequency == 0 || _current_ripple == 0) {
        std::cerr << "Error: Switching frequency or current ripple cannot be zero for inductor calculation.\n";
        return 0.0f;
    }
    return (_input_voltage - _output_voltage) * duty_ratio / (_switching_frequency * _current_ripple);
}

float BuckConverter::calculate_capacitor_value() {
    float duty_ratio = calculate_duty_ratio();
    if (duty_ratio == 0) {
        std::cerr << "Error: Duty ratio calculation failed.\n";
        return 0.0f;
    }

    float inductor_value = calculate_inductor_value(); // Call directly
    if (inductor_value == 0) {
        std::cerr << "Error: Inductor value calculation failed.\n";
        return 0.0f;
    }

    // Use inductor_value in capacitor calculation
    return (_output_voltage * (1 - duty_ratio)) / 
           (8 * _voltage_ripple * inductor_value * _switching_frequency * _switching_frequency);
}


BoostConverter::BoostConverter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float load_resistance) {
    _switching_frequency = switching_frequency;
    _input_voltage = input_voltage;
    _output_voltage = output_voltage;
    _current_ripple = current_ripple;
    _voltage_ripple = voltage_ripple;
    _load_resistance = load_resistance;
}

float BoostConverter::calculate_duty_ratio() {
    if (_input_voltage == 0 || _output_voltage == 0) {
        std::cerr << "Error: Input or output voltage cannot be zero for duty ratio calculation.\n";
        return 0.0f;
    }
    return 1 - (_input_voltage / _output_voltage);
}

float BoostConverter::calculate_inductor_value() {
    float duty_ratio = calculate_duty_ratio();
    if (duty_ratio == 0) {
        std::cerr << "Error: Duty ratio calculation failed.\n";
        return 0.0f;
    }
    return (_input_voltage * duty_ratio) / (_switching_frequency * _current_ripple);
}

float BoostConverter::calculate_capacitor_value() {
    float duty_ratio = calculate_duty_ratio();
    if (duty_ratio == 0) {
        std::cerr << "Error: Duty ratio calculation failed.\n";
        return 0.0f;
    }
    return (_output_voltage * duty_ratio) / (_load_resistance * _switching_frequency * _voltage_ripple);
}
