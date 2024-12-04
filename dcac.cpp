#include <string>
#include <iostream>
#include <regex> // needed to parse inputs

#include "dcac.h"

DCAC::DCAC() {}

bool is_integer(std::string num); // check input is an integer
bool is_float(std:: string num); // check input is a float

void sub_menu_item_1() {
  std::cout << "\n>> This is a bipolar DC-AC Inverter.\n";
  std::cout << "\nSome code here does something useful\n";
  DCAC bipolar;
  // you can call a function from here that handles menu 1
}
void sub_menu_item_2() {
  std::cout << "\n>> This is a unipolar DC-AC\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 2

}

// Sub-Menu Sub-Functions
int polarity_choice() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 3;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void select_sub_menu_item(int subinput) {
  switch (subinput) {
    case 1:
      sub_menu_item_1();
      break;
    case 2:
      sub_menu_item_2();
      break;
    default:
      std::cout << "Returning to Main Menu\n";
      break;
  }
}


void DCAC::set_Vi() {
  float Vi;
  std::string Vi_string;
  bool valid_input = false;
  std::cout << "\nEnter a new value for the input DC voltage (in volts): " << std::endl;
  do {
    std::cin >> Vi_string;
    valid_input = is_float(Vi_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "Enter a number\n";
    } else {  // if it is an int, check whether in range
      Vi = std::stof(Vi_string);  // convert to int
      if (Vi < 0) {
        std::cout << "Enter a postive value\n";
        valid_input = false;
      } else {
        valid_input = true;
        }
    }
  } while (valid_input == false);
  _Vi = Vi;
}

void DCAC::set_ma() {
  float ma;
  std::string ma_string;
  bool valid_input = false;
  std::cout << "\nEnter a new value for the modulation index: " << std::endl;
  do {
    std::cin >> ma_string;
    valid_input = is_float(ma_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "Enter a number\n";
    } else {  // if it is an float, check whether in range
      ma = std::stof(ma_string);  // convert to float
      if (ma >= 0 && ma <= 1) {
        valid_input = true;
      } else {
        std::cout << "Enter a value between 0 and 1\n";
        valid_input = false;
        }
    }
  } while (valid_input == false);
  _ma = ma;
}

void DCAC::set_bi_efficiency() {
  float efficiency;
  std::string efficiency_string;
  bool valid_input = false;
  std::cout << "\nTypical efficiency percentages for a bipolar inverter range from 75-85%."
            <<"\nEnter a new value for the Inverter efficiency: " << std::endl;
  do {
    std::cin >> efficiency_string;
    valid_input = is_float(efficiency_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "Enter a number\n";
    } else {  // if it is a float, check whether in range
      efficiency = std::stof(efficiency_string);  // convert to float
      if (efficiency >= 75 && efficiency <= 85) {
        valid_input = true;
      } else {
        std::cout << "Enter a value between 75 and 85\n";
        valid_input = false;
        }
    }
  } while (valid_input == false);
  _bi_efficiency = efficiency;
}

void DCAC::set_uni_efficiency() {
  float efficiency;
  std::string efficiency_string;
  bool valid_input = false;
  std::cout << "\nTypical efficiency percentages for a unipolar inverter range from 85-95%."
            << "\nEnter a new value for the Inverter efficiency (in %): " << std::endl;
  do {
    std::cin >> efficiency_string;
    valid_input = is_float(efficiency_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "Enter a number\n";
    } else {  // if it is a float, check whether in range
      efficiency = std::stof(efficiency_string);  // convert to float
      if (efficiency >= 85 && efficiency <= 95) {
        valid_input = true;
      } else {
        std::cout << "Enter a value between 85 and 95\n";
        valid_input = false;
        }
    }
  } while (valid_input == false);
  _uni_efficiency = efficiency;
}

void DCAC::set_f() {
  float f;
  std::string f_string;
  bool valid_input = false;
  std::cout << "\nEnter a new value for the frequency (in hertz): " << std::endl;
  do {
    std::cin >> f_string;
    valid_input = is_float(f_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "Enter a number\n";
    } else {  // if it is an float, check whether in range
      f = std::stof(f_string);  // convert to float
      if (f > 0) {
        valid_input = true;
      } else {
        std::cout << "Enter a value greater than 0\n";
        valid_input = false;
        }
    }
  } while (valid_input == false);
  _f = f;
}

void DCAC::set_L() {
  float L;
  std::string L_string;
  bool valid_input = false;
  std::cout << "\nEnter a new value for the inductor (in milli Henry): " << std::endl;
  do {
    std::cin >> L_string;
    valid_input = is_float(L_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "Enter a number\n";
    } else {  // if it is an float, check whether in range
      L = std::stof(L_string);  // convert to float
      if (0 < L && L < 50) {
        valid_input = true;
      } else if (L > 50) {
        std::cout << "Enter a value less than 50mH\n";
        valid_input = false;
        } else {
          std::cout << "Enter a positive value\n";
          valid_input = false;
        }
    }
  } while (valid_input == false);
  _L = L;
}

float DCAC::get_Vi() {
  return _Vi;
}

float DCAC::get_ma() {
  return _ma;
}

float DCAC::get_bi_efficiency() {
  return _bi_efficiency;
}

float DCAC::get_uni_efficiency() {
  return _uni_efficiency;
}

float DCAC::get_f() {
  return _f;
}

float DCAC::get_L() {
  return _L;
}

// https://stackoverflow.com/questions/12643009/regular-expression-for-floating-point-numbers
bool is_float(std::string num) {
  return std::regex_match(num, std::regex("[+-]?([0-9]*[.])?[0-9]+"));
}