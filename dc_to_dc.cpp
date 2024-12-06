#include <iostream>
#include "dc_to_dc.h"

//Constructor: Initialized the Buck Converter with given parameters
BuckConverter::BuckConverter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple) {
    _switching_frequency = switching_frequency;
    _input_voltage = input_voltage;
    _output_voltage = output_voltage;
    _current_ripple = current_ripple;
    _voltage_ripple = voltage_ripple;
}
//Calculate duty ratio for buck converter circuit
float BuckConverter::calculate_duty_ratio() {
    //Checks that the input voltage given by the user is not zero
    if (_input_voltage == 0) {
        std::cerr << "Error: Input voltage cannot be zero for duty ratio calculation.\n";
        return 0.0f; //Indicates failure of execution
    }

    return _output_voltage / _input_voltage;
}

float BuckConverter::calculate_inductor_value() {
    float duty_ratio = calculate_duty_ratio();
    //Check that the calculated duty ratio is not zero
    if (duty_ratio == 0) {
        std::cerr << "Error: Duty ratio calculation failed.\n";
        return 0.0f; //Indicates failure of execution
    }
    if (_switching_frequency == 0 or _current_ripple == 0) {
        std::cerr << "Error: Switching frequency or current ripple cannot be zero for inductor calculation.\n";
        return 0.0f; //Indicates failure of execution
    }
    //Calculate the inductor for the buck converter cicuit
    return (_input_voltage - _output_voltage) * duty_ratio / (_switching_frequency * _current_ripple);
}

float BuckConverter::calculate_capacitor_value() {
    float duty_ratio = calculate_duty_ratio();
    //Check that the calculated duty ratio is not zero
    if (duty_ratio == 0) {
        return 0.0f; //Indicates failure of execution
    }

    float inductor_value = calculate_inductor_value();
    //Check that the calculated induction zero is not zero
    if (inductor_value == 0) {
        std::cerr << "Error: Inductor value calculation failed.\n";
        return 0.0f; //Indicates failure of execution
    }
    
    //Calculate the capacitor for the buck converter circuit
    return (_output_voltage * (1 - duty_ratio)) / 
           (8 * _voltage_ripple * inductor_value * _switching_frequency * _switching_frequency);
}

//Constructor: Initialized the Boost Converter with given parameters
BoostConverter::BoostConverter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float resistance_value) {
    _switching_frequency = switching_frequency;
    _input_voltage = input_voltage;
    _output_voltage = output_voltage;
    _current_ripple = current_ripple;
    _voltage_ripple = voltage_ripple;
    _resistance_value = resistance_value;
}

//Calculate the duty ratio for boost converter
float BoostConverter::calculate_duty_ratio() {
    if (_input_voltage == 0 or _output_voltage == 0) {
        std::cerr << "Error: Input or output voltage cannot be zero for duty ratio calculation.\n";
        return 0.0f; //Indicates failure of execution
    }
    return 1 - (_input_voltage / _output_voltage);
}

float BoostConverter::calculate_inductor_value() {
    float duty_ratio = calculate_duty_ratio();
    if (duty_ratio == 0) {
        std::cerr << "Error: Duty ratio calculation failed.\n";
        return 0.0f; //Indicates failure of execution
    }
    //Calculate the inductor for the boost converter cicuit
    return (_input_voltage * duty_ratio) / (_switching_frequency * _current_ripple);
}

float BoostConverter::calculate_capacitor_value() {
    float duty_ratio = calculate_duty_ratio();
    if (duty_ratio == 0) {
        return 0.0f; //Indicates failure of execution
    }
    //Calculate the capacitor for the buck converter circuit
    return (_output_voltage * duty_ratio) / (_resistance_value * _switching_frequency * _voltage_ripple);
}
