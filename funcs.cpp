#include <string>
#include <iostream>
#include <regex>

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
  float switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, load_resistance, duty_ratio, inductor_value, capacitor_value;
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

  do {
    std::cout << "Enter switching frequency (Hz): ";
    std::cin >> user_string;

    if (!isFloat(user_string)) {
        std::cout << "Invalid: Enter a real number (R)\n";
    } else {
        switching_frequency = std::stof(user_string);

        if (switching_frequency < 1000) {
            std::cout << "Invalid: Switching frequency must be at least 1000 Hz.\n";
        } else {
            valid_input = true;
        }
    }
} while (!valid_input);

  do{
    std::cout << "Enter input voltage(V)): ";
    std::cin >> user_string;
    if(!isFloat(user_string)){
      std::cout << "Invalid: Enter a real number (ℝ)\n";
    } else{
      valid_input = true;
      input_voltage = std::stof(user_string);
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
      output_voltage = std::stof(user_string);
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
      current_ripple = std::stof(user_string);
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
      voltage_ripple = std::stof(user_string);
    }
    }while(!valid_input);

    valid_input = false;

  do{
    std::cout << "Enter load resistance(Ω): ";
    std::cin >> user_string;
    if(!isFloat(user_string)){
      std::cout << "Invalid: Enter a real number (ℝ)\n";
    } else{
      valid_input = true;
      load_resistance = std::stof(user_string);
    }
    }while(!valid_input);

    valid_input = false;

  switch(converter_option){
      case 1:
      break;
      case 2:
      do{
      std::cout << "Enter load_resistance (Ω): ";
      std::cin >> user_string;

      if(!isFloat(user_string)){
        std::cout << "Invalid: Enter a real number (ℝ\n";
      } else{

        load_resistance = std::stof(user_string);
        if(load_resistance < 0){
          std::cout << "Load Resistance must be positive\n";
        } else {
          valid_input = true;
        }
      }
    }while(!valid_input);
    break;
    }

  switch(converter_option){
    case 1:
    buck_converter(switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, &duty_ratio, &inductor_value, &capacitor_value);
    break;
    case 2:
    boost_converter(switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, load_resistance, &duty_ratio, &inductor_value, &capacitor_value);
    break;
  }
  //output results
  final_results(duty_ratio, inductor_value, capacitor_value, converter_option);
}

void buck_converter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float* duty_ratio, float* inductor_value, float* capacitor_value){
  BuckConverter converter(switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple);
  *duty_ratio = converter.calculate_duty_ratio();
  *inductor_value = converter.calculate_inductor_value();
  *capacitor_value = converter.calculate_capacitor_value();

}

void boost_converter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float load_resistance, float* duty_ratio, float* inductor_value, float* capacitor_value){
  BoostConverter converter(switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, load_resistance);
  *duty_ratio = converter.calculate_duty_ratio();
  *inductor_value = converter.calculate_inductor_value();
  *capacitor_value = converter.calculate_capacitor_value();
}

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

void final_results(float duty_ratio, float inductor_value, float capacitor_value, int converter_option){
  std::cout << "\n----------- Results ------------\n";
  std::cout << "\n";
  std::cout << "Duty Ratio = " << duty_ratio << " \n";
  std::cout << "inductor = " << inductor_value << " H\n";
  std::cout << "capacitor = " << capacitor_value << " C\n";
  std::cout << "\n";
  std::cout << "-----------------------------------------\n";
}