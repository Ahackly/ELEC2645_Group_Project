#ifndef AC_TO_DC_H
#define AC_TO_DC_H

class FullyControlled {
    public:
    //Constructor
    FullyControlled(float vs, float alpha, float load_resistance);
    
    float calculate_output_voltage();
    float calculate_power_factor();
    
    private:
        float _vs; //input voltage
        float _vo; //output voltage
        float _alpha; //delay angle
        float _load_resistance;
        float _pf; //power factor
};

class HalfControlled {
    public:
    //Constructor
    HalfControlled(float vs, float alpha, float load_resistance);
    private:
        float _vs; //input voltage
        float _vo; //output voltage
        float _alpha; //delay angle
        float _load_resistance;
        float _pf; //power factor
};

#endif // AC_TO_DC_H