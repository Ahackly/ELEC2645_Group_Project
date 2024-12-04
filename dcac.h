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
    void set_ma();
    void set_bi_efficiency();
    void set_uni_efficiency();
    void set_f();
    void set_L();
    // Accessors
    float get_Vi();
    float get_ma();
    float get_bi_efficiency();
    float get_uni_efficiency();
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
    float _bi_efficiency = 85;
    float _uni_efficiency = 95;
    float _f = 50;
    float _L = 50;
};

#endif