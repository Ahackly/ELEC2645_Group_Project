#ifndef FUNCS_H
#define FUNCS_H

void dc_to_dc();
void menu_item_2();
void menu_item_3();
void print_dc_dc_menu();
int get_user_input_dc_dc();
void select_menu_item_dc_dc(int input);
void converter_input_parameters(int converter_option);
void buck_converter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float* duty_ratio, float* inductor_value, float* capacitor_value);
void boost_converter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float load_resistance, float* duty_ratio, float* inductor_value, float* capacitor_value);
void final_results(float duty_ratio, float inductor_value, float capacitor_value, int converter_option);
bool isFloat(const std::string& input);


#endif