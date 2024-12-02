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
  std::string input_string;
  float input_voltage, alpha, output_voltage, power_factor, load_resistance;
  bool valid_input = false;

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

    //check if input is a float
    do{
    std::cout << "Enter input voltage(Volts rms): ";
    std::cin >> input_string;
    if(!isFloat(input_string)){
      std::cout << "Enter a float!!!\n";
    } else{
      valid_input = true;
      input_voltage = std::stof(input_string);
    }
    }while(!valid_input);

     //check if input is a float
    valid_input = false;

    do{
    std::cout << "Enter delay angle (degrees): ";
    std::cin >> input_string;

    if(!isFloat(input_string)){
      std::cout << "Enter a float!!!!\n";
    } else{

      //check if alpha is in range
      alpha = std::stof(input_string);
      if(alpha < 0 || alpha > 180){
          std::cout << "angle alpha must be between 0 and 180\n";
        } else {
          valid_input = true;
        }
    }
    }while(!valid_input);

    valid_input = false;

     //check if input is a float
    switch(rec_type){
      case 1:
      break;
      case 2:
      do{
      std::cout << "Enter load_resistance (Ohms): ";
      std::cin >> input_string;

      if(!isFloat(input_string)){
        std::cout << "Enter a float!!!!\n";
      } else{

        //check if resistance is negative
        load_resistance = std::stof(input_string);
        if(load_resistance < 0){
          std::cout << "Load Resistance must be positive\n";
        } else {
          valid_input = true;
        }
      }
    }while(!valid_input);
    break;
    }

    std::cout << "\n";
    std::cout << "-----------------------------------------\n";
    
  //call the right function
  switch(rec_type){
    case 1:
    fully_controlled(input_voltage, alpha, &output_voltage, &power_factor);
    break;
    case 2:
    half_controlled(input_voltage, alpha, load_resistance, &output_voltage, &power_factor);
    break;
  }
  //output results
  output_results(output_voltage, power_factor, rec_type);
}

void fully_controlled(float input_voltage, float alpha, float* output_voltage, float* power_factor){
  FullyControlled rectifier(input_voltage, alpha);
  *output_voltage = rectifier.calculate_output_voltage();
  *power_factor = rectifier.calculate_power_factor();
}

void half_controlled(float input_voltage, float alpha, float load_resistance,  float* output_voltage, float* power_factor){
  HalfControlled rectifier(input_voltage, alpha, load_resistance);
  *output_voltage = rectifier.calculate_output_voltage();
  *power_factor = rectifier.calculate_power_factor();
}

//Function to check if a string input is a float
bool isFloat(const std::string& input) {
    int dot_count = 0; // To track the number of decimal points
    int digit_count = 0; // To ensure there is at least one digit

    for (size_t i = 0; i < input.length(); ++i) {
        char ch = input[i];

        // Check for a sign at the beginning
        if ((ch == '+' || ch == '-') && i == 0) {
            continue;
        }
        // Check for digits
        if (ch >= '0' && ch <= '9') {
            ++digit_count;
            continue;
        }
        // Check for a single decimal point
        if (ch == '.') {
            ++dot_count;
            if (dot_count > 1) {
                return false; // More than one dot is invalid
            }
            continue;
        }
        // Invalid character found
        return false;
    }

    // Valid if there's at least one digit and at most one dot
    return digit_count > 0 && dot_count <= 1;
}

void output_results(float output_voltage, float power_factor, int rec_type){
  std::cout << "\n----------- Results ------------\n";
  std::cout << "\n";
  std::cout << "Output Voltage = " << output_voltage << " V\n";
  std::cout << "Power Factor = " << power_factor << "\n";
  std::cout << "\n";
  std::cout << "-----------------------------------------\n";
}