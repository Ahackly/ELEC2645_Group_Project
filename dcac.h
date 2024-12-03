#ifndef DCAC_H
#define DCAC_H

#define PI 3.14159265

int polarity_choice();
void select_sub_menu_item(int input); // run the desired code based on the users choice

class DCAC {
    public:
    DCAC(); // Constructor
    // Mutators
    void set_Vi();
    void set_ma(float ma);
    void set_efficiency(float efficiency);
    void set_f(float f);
    void set_L(float L);
    // Accessors
    float get_Vi();
    float get_ma();
    float get_efficiency();
    float get_f();
    float get_L();
    float get_VAB();
    float get_Vo();
    float get_Io();
    float get_R();
    float get_P();
    private:
    float _Vi = 450;
    float _ma = 0.75;
    float _efficiency = 95;
    float _f = 50;
    float _L = 50;
};

#endif