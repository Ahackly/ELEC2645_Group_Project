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
    return 0.9* cos(_alpha);
}

HalfControlled::HalfControlled(float input_voltage, float alpha){
    _input_voltage = input_voltage;

    //convert angle to radians
    _alpha = alpha * PI/180;
}

float HalfControlled::calculate_output_voltage(){
    return 0.45*_input_voltage*(1+cos(_alpha));
}

float HalfControlled::calculate_power_factor(){
    return 0.9* cos(_alpha);
}