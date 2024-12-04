#ifndef DC_TO_DC_H
#define DC_TO_DC_H

class BuckConverter {
    public:
    //Constructor
    BuckConverter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple);
    
    float calculate_duty_ratio();
    float calculate_inductor_value();
    float calculate_capacitor_value();

    private:
        float _switching_frequency;
        float _input_voltage;
        float _output_voltage;
        float _current_ripple;
        float _voltage_ripple;
};

class BoostConverter {
    public:
    //Constructor
    BoostConverter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float load_resistance);

    float calculate_duty_ratio();
    float calculate_inductor_value();
    float calculate_capacitor_value();

    private:
        float _switching_frequency;
        float _input_voltage;
        float _output_voltage;
        float _current_ripple;
        float _voltage_ripple;
        float _load_resistance;
};

#endif