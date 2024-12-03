#include <iostream>
#include <iostream>

BuckConverter::BuckConverter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple){
    _switching_frequency = switching_frequency;
    _input_voltage = input_voltage;
    _output_voltage = output_voltage;
    _current_ripple = current_ripple;
    _voltage_ripple = voltage_ripple;
}

float BuckConverter::calculate_duty_ratio(){
    return _ouput_voltage/_input_voltage;
}

float BuckConverter::calculate_inductor_value(){
    return (_input_voltage - _ouput_voltage)*calculate_duty_ratio/(_switching_frequency/_current_ripple);
}

float BuckConverter::calculate_capacitor_value(){
    return (_output_voltage*(1 - calculate_duty_ratio))/(8 * _voltage_ripple * _switching_frequency);
}

BoostConverter::BoostConverter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float load_resistance){
    _switching_frequency = switching_frequency;
    _input_voltage = input_voltage;
    _output_voltage = output_voltage;
    _current_ripple = current_ripple;
    _voltage_ripple = voltage_ripple;
    _load_resistance = load_resistance;
}

float BoostConverter::calculate_duty_ratio(){
    return 1 - (1/(_ouput_voltage/_input_voltage));
}

float BoostConverter::calculate_inductor_value(){
    return (_input_voltage * calculate_duty_ratio)/(_switching_frequency * _current_ripple);
}

float BoostConverter::calculate_capacitor_value(){
    return (_output_voltage * calculate_duty_ratio)/(__load_resistance * _switching_frequency * _voltage_ripple);
}