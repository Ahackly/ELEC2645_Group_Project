#include <string>
#include <iostream>

#include "funcs.h"
#include <regex>

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

