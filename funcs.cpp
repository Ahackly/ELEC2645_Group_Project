#include <string>
#include <iostream>
#include <regex>

#include "funcs.h"
#include "ac_to_dc.h"


void menu_item_1() {
  std::cout << "\n>> Menu 1\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 1

}
void ac_to_dc() {
  print_ac_to_dc_menu();
  int input =  get_user_input2();
  select_menu_item_2(input);
}
void menu_item_3() {
  std::cout << "\n>> Menu 3\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 3

}

//This function gets input parameters and calls the right function and prints the results
void rectifire_iput_parameters(int rec_type){
  float input_voltage, alpha, load_resistance, output_voltage, power_factor;
  
  //print menu
  switch(rec_type){
    case 1:
    std::cout << "\n----------- Fully Controlled -----------\n";
    break;
    case 2:
    std::cout << "\n----------- Half Controlled ------------\n";
    break;
  }
  std::cout << "\n";
  std::cout << "Enter input voltage: ";
  std::cin >> input_voltage;
  std::cout << "Enter delay angle: ";
  std::cin >> alpha;
  std::cout << "Enter load resistance:  ";
  std::cin >> load_resistance;
  std::cout << "\n";
  std::cout << "-----------------------------------------\n";

  //Verify user input
  
  //call the right function
  switch(rec_type){
    case 1:
    fully_controlled(input_voltage, alpha, load_resistance, &output_voltage, &power_factor);
    break;
    case 2:
    half_controlled(input_voltage, alpha, load_resistance, &output_voltage, &power_factor);
    break;
  }
  //output results
}

void fully_controlled(float input_voltage, float alpha, float load_resistance, float* output_voltage, float* power_factor){
  FullyControlled rectifier(input_voltage, alpha, load_resistance);
}

void half_controlled(float input_voltage, float alpha, float load_resistance, float* output_voltage, float* power_factor){
  HalfControlled rectifier(input_voltage, alpha, load_resistance);
}