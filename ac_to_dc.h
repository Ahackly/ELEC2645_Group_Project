#ifndef AC_TO_DC_H
#define AC_TO_DC_H

class FullyControlled {
    public:
    //Constructor
    FullyControlled(float input_voltage, float alpha);
    
    float calculate_output_voltage();
    float calculate_power_factor();
    
    private:
        float _input_voltage; //input voltage
        float _alpha; //delay angle
};

class HalfControlled {
    public:
    //Constructor
    HalfControlled(float input_voltage, float alpha, float load_resistance);

    float calculate_output_voltage();
    float calculate_power_factor();

    private:
        float _input_voltage; //input voltage
        float _alpha; //delay angle
        float _load_resistance;
};
#endif // AC_TO_DC_H