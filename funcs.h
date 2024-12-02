#ifndef FUNCS_H
#define FUNCS_H

void menu_item_1();
void ac_to_dc();
void menu_item_3();
void print_ac_to_dc_menu();
int get_user_input2();
void select_menu_item_2(int input);
void rectifire_iput_parameters(int rec_type);
void fully_controlled(float input_voltage, float alpha, float load_resistance, float* output_voltage, float* power_factor);
void half_controlled(float input_voltage, float alpha, float load_resistance, float* output_voltage, float* power_factor);
#endif