#ifndef DCAC_H
#define DCAC_H

#define PI 3.14159265

int polarity_choice(); // Choose a valid input for sub-menu
void select_sub_menu_item(int sub_input); // run the desired sub-menu based on the users choice
int input_choice(); // Choose a valid input value
void change_bi_input_value(int val_input); // Change the chosen value for bipolar inverter
void change_uni_input_value(int val_input); // Change the chosen value for unipolar inverter
void bi_display(); // prints bipolar inverter display
void uni_display(); // prints unipolar inverter display
void exit_inverter(); // Exits to sub-menu display

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
    float get_efficiency();
    float get_f();
    float get_L();
    float get_VAB();
    float get_Vo();
    float get_Io();
    float get_R();
    float get_P();
    float get_theta();
    private:
    float _Vi = 450;
    float _ma = 0.75;
    float _efficiency = 85;
    float _f = 50;
    float _L = 50;
    float _VAB;
    float _Vo;
    float _Io;
    float _R;
    float _P;
    float _theta;
};

#endif