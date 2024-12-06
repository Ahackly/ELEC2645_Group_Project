#include <string>
#include <iostream>
#include <regex>

#include "funcs.h"
#include "dc_to_dc.h"

//Function to handle DC-DC converter menu
void dc_to_dc() {
  print_dc_dc_menu();
  int input = get_user_input_dc_dc();//Gets user input
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
//Function to get input parameters
void converter_input_parameters(int converter_option) {
    std::string user_string;
    float switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, resistance_value, duty_ratio, inductor_value, capacitor_value;
    bool valid_input = false;

    switch (converter_option) {
        case 1:
            std::cout << "\n----------- Buck Converter -----------\n";
            break;
        case 2:
            std::cout << "\n----------- Boost Converter ------------\n";
            break;
    }
    std::cout << "\n";

    do {
        //Gets switching frequency from user
        valid_input = true;
      
        std::cout << "Enter switching frequency (Hz) - Minimum: 1000Hz: ";
        std::cin >> user_string;
        if (!isFloat(user_string)) { //Checks if input is a real number
            std::cout << "Invalid: Enter a real number (R)\n";
            valid_input = false;
            continue;
        }

        switching_frequency = std::stof(user_string);

        if (switching_frequency < 1000) {
            std::cout << "Invalid: Enter a number greater than or equal to 1000 \n";
                valid_input = false;
        }
        //Gets input voltage from user
        if (valid_input) {
            std::cout << "Enter input voltage (V): ";
            std::cin >> user_string;
            if (!isFloat(user_string)) { //Checks if input is a real number
                std::cout << "Invalid: Enter a real number (R)\n";
                valid_input = false;
            } else {
                input_voltage = std::stof(user_string);
            }
        }
        //Gets output voltage from user
        if (valid_input) {
            std::cout << "Enter output voltage (V): ";
            std::cin >> user_string;
            if (!isFloat(user_string)) { //Checks if input is a real number
                std::cout << "Invalid: Enter a real number (R)\n";
                valid_input = false;
            } else {
                output_voltage = std::stof(user_string);
            }
        }
        //Check if the user entered a lower output voltage than the input voltage
        if (valid_input and converter_option == 1 and input_voltage <= output_voltage) {
            std::cout << "Error: For a buck converter, the input voltage must be greater than the output voltage.\n";
            valid_input = false;
        }

    } while (!valid_input);

    do {
        valid_input = true; 
        //Gets output current ripple from user
        std::cout << "Enter output current ripple (%): ";
        std::cin >> user_string;
        if (!isFloat(user_string)) { //Checks if input is a real number
            std::cout << "Invalid: Enter a real number (R)\n";
                valid_input = false;
                continue;
        }

        current_ripple = std::stof(user_string);

        //Check if the input is between 0 and 100
        if ((current_ripple  <= 0) or (current_ripple > 100)) {
            std::cout << "Invalid: Enter a number between 0 and 100 \n";
                valid_input = false;
        }
    } while (!valid_input);

    do {
        valid_input = true; 
        //Gets output voltage ripple from user
        std::cout << "Enter output voltage ripple (%): ";
        std::cin >> user_string;
        if (!isFloat(user_string)) { //Checks if input is a real number
            std::cout << "Invalid: Enter a real number (R)\n";
                valid_input = false;
                continue;
        }

        voltage_ripple = std::stof(user_string);

        //Check if the input is between 0 and 100
        if ((voltage_ripple  <=0) or (voltage_ripple > 100)) {
            std::cout << "Invalid: Enter a number between 0 and 100 \n";
                valid_input = false;
        }
    } while (!valid_input);

    //Gets resistance value from the user only if boost converter is selected
    if (converter_option == 2) {
        valid_input = true;

        do {
            std::cout << "Enter load resistance (Ohms): ";
            std::cin >> user_string;
            if (!isFloat(user_string)) { //Checks if input is a real number
                std::cout << "Invalid: Enter a real number (R).\n";
                valid_input = false;
                continue;
            } else {
            valid_input = true;
        }
        } while (!valid_input);
    }

    //Calls converter function based on the user's choice
    if (converter_option == 1) {
        buck_converter(switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, &duty_ratio, &inductor_value, &capacitor_value);
    } else if (converter_option == 2) {
        boost_converter(switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, resistance_value, &duty_ratio, &inductor_value, &capacitor_value);
    }

    //Ouputs final results
    final_results(duty_ratio, inductor_value, capacitor_value, converter_option);
}

//Function to calculates values for buck converter
void buck_converter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float* duty_ratio, float* inductor_value, float* capacitor_value){
  BuckConverter converter(switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple);
  *duty_ratio = converter.calculate_duty_ratio();
  *inductor_value = converter.calculate_inductor_value();
  *capacitor_value = converter.calculate_capacitor_value();

}

//Function to calculates values for boost converter
void boost_converter(float switching_frequency, float input_voltage, float output_voltage, float current_ripple, float voltage_ripple, float resistance_value, float* duty_ratio, float* inductor_value, float* capacitor_value){
  BoostConverter converter(switching_frequency, input_voltage, output_voltage, current_ripple, voltage_ripple, resistance_value);
  *duty_ratio = converter.calculate_duty_ratio();
  *inductor_value = converter.calculate_inductor_value();
  *capacitor_value = converter.calculate_capacitor_value();
}

//Function to check if input is a float
bool isFloat(const std::string& input) {
    int dot_count = 0;
    int digit_count = 0;

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

//Displays final results
void final_results(float duty_ratio, float inductor_value, float capacitor_value, int converter_option){
  std::cout << "\n----------- Results ------------\n";
  std::cout << "\n";
  std::cout << "Duty Ratio = " << duty_ratio << " \n";
  std::cout << "inductor = " << inductor_value << " H\n";
  std::cout << "capacitor = " << capacitor_value << " F\n";
  std::cout << "\n";
  std::cout << "-----------------------------------------\n";
}