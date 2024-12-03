#include <string>
#include <iostream>

#include "funcs.h"
#include "dc_to_dc.h"

void dc_to_dc() {
  print_dc_dc_menu();
  int input = get_user_input_dc_dc();
  select_menu_item_dc_dc(input);  // you can call a function from here that handles menu 1

}
void menu_item_2() {
  std::cout << "\n>> Menu 2\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 2

}
void menu_item_3() {
  std::cout << "\n>> Menu 3\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 3

}

void converter_input_parameters(int converter_option){
  std::string user_string;
  float switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, duty_ratio, inductor_value, capacitor_value;
  bool valid_input = false;
  switch(converter_option){
    case 1:
    std::cout << "\n----------- Buck Converter -----------\n";
    break;
    case 2:
    std::cout << "\n----------- Boost Converter ------------\n";
    break;
}
    std::cout << "\n";

  do{
    std::cout << "Enter switching frequency(Hz): ";
    std::cin >> user_string;
    if(!isFloat(user_string)){
      std::cout << "Invalid: Enter a real number (ℝ)\n";
    } else{
      valid_input = true;
      switching_frequency = std::stof(user_string);
    }
    }while(!valid_input);

    valid_input = false;
  
  do{
    std::cout << "Enter input voltage(V)): ";
    std::cin >> user_string;
    if(!isFloat(user_string)){
      std::cout << "Invalid: Enter a real number (ℝ)\n";
    } else{
      valid_input = true;
      switching_frequency = std::stof(user_string);
    }
    }while(!valid_input);

    valid_input = false;

  do{
    std::cout << "Enter output voltage(V): ";
    std::cin >> user_string;
    if(!isFloat(user_string)){
      std::cout << "Invalid: Enter a real number (ℝ)\n";
    } else{
      valid_input = true;
      switching_frequency = std::stof(user_string);
    }
    }while(!valid_input);

    valid_input = false;
  
  do{
    std::cout << "Enter ouput current ripple(%): ";
    std::cin >> user_string;
    if(!isFloat(user_string)){
      std::cout << "Invalid: Enter a real number (ℝ)\n";
    } else{
      valid_input = true;
      switching_frequency = std::stof(user_string);
    }
    }while(!valid_input);

    valid_input = false;

  do{
    std::cout << "Enter ouput voltage ripple(%): ";
    std::cin >> user_string;
    if(!isFloat(user_string)){
      std::cout << "Invalid: Enter a real number (ℝ)\n";
    } else{
      valid_input = true;
      switching_frequency = std::stof(user_string);
    }
    }while(!valid_input);

    valid_input = false;

  switch(converter_option){
      case 1:
      break;
      case 2:
      do{
      std::cout << "Enter load_resistance (Ohms): ";
      std::cin >> input_string;

      if(!isFloat(input_string)){
        std::cout << "Enter a float!!!!\n";
      }
