#include <string>
#include <iostream>

#include "funcs.h"
#include "dcac.h" // dc-ac class


void menu_item_1() {
  std::cout << "\n>> Menu 1\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 1

}
void menu_item_2() {
  std::cout << "\n>> Menu 2\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 2

}
void menu_item_3() {
  std::cout << "\n----------- -DC-AC~ Inverter ------------\n|";
  std::cout << "\t\t\t\t\t|\n|\t1. Bipolar Switching\t\t|\n|";
  std::cout << "\t\t\t\t\t|\n|\t2. Unipolar Switching\t\t|\n|";
  std::cout << "\t\t\t\t\t|\n|\t3. Return to Main Menu\t\t|\n|";
  std::cout << "\t\t\t\t\t|\n-----------------------------------------\n";
  int subinput = polarity_choice(); // same as get_user_input function from main
  select_sub_menu_item(subinput); // same as select_menu_item function from main
}
void menu_item_4() {
  std::cout << "\n>> Menu 4\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 4

}