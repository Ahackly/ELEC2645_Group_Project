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
  bipolar.set_Vi();
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
  std::cout << "Enter a new value for the input DC voltage: " << std::endl;
  do {
    std::cin >> Vi_string;
    valid_input = is_float(Vi_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "Enter a number!\n";
    } else {  // if it is an int, check whether in range
      Vi = std::stof(Vi_string);  // convert to int
      if (Vi < 0) {
        std::cout << "Enter a postive value!\n";
        valid_input = false;
      } else {
        valid_input = true;
        }
    }
  } while (valid_input == false);
  _Vi = Vi;
}

// https://stackoverflow.com/questions/12643009/regular-expression-for-floating-point-numbers
bool is_float(std::string num) {
  return std::regex_match(num, std::regex("[+-]?([0-9]*[.])?[0-9]+"));
}