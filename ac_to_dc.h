#ifndef AC_TO_DC_H
#define AC_TO_DC_H

class FullyControlled {
    public:
    //Constructor
    FullyControlled(float vs, float alpha, float load_resistance);
    
    
    private:
        float _vs; //input voltage
        float _vo; //output voltage
        float _io; //output current
        float _alpha; //delay angle
        float _load_resistance;
        float _pf; //power factor
        float _active_power; //average power
};

class HalfControlled {
    public:
    //Constructor
    HalfControlled(float vs, float alpha, float load_resistance);
    private:
        float _vs; //input voltage
        float _vo; //output voltage
        float _io; //output current
        float _alpha; //delay angle
        float _load_resistance;
        float _pf; //power factor
        float _active_power; //average power
};

#endif // AC_TO_DC_H