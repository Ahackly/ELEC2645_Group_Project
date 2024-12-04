#include <iostream>
#include <cmath>
#include "ac_to_dc.h"

#define PI 3.141592653589793
FullyControlled::FullyControlled(float input_voltage, float alpha){
    _input_voltage = input_voltage;

    //convert angle to radians
    _alpha = alpha * PI/180;
}

float FullyControlled::calculate_output_voltage(){
    return 0.9*_input_voltage*cos(_alpha);
}

float FullyControlled::calculate_power_factor(){
    return fabs(0.9* cos(_alpha));
}

HalfControlled::HalfControlled(float input_voltage, float alpha, float load_resistance){
    _input_voltage = input_voltage;

    //convert angle to radians
    _alpha = alpha * PI/180;

    _load_resistance = load_resistance;
}

float HalfControlled::calculate_output_voltage(){
    return 0.45*_input_voltage*(1+cos(_alpha));
}

float HalfControlled::calculate_power_factor(){
    float output_voltage = 0.45*_input_voltage*(1+cos(_alpha));
    float output_current = output_voltage / _load_resistance;
    float input_current = output_current * sqrt(1-(_alpha/PI));
    float output_power = output_current * output_current * _load_resistance;
    return fabs(output_power / (_input_voltage * input_current));
}