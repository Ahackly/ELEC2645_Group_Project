//ELEC/XJEL2645 - Simple Command Line Interface example
// Dr Craig A. Evans, Dr Tim J. Amsdon and Dr James Avery

#include <iostream>
#include <regex> // needed to parse inputs
#include "funcs.h" // sub functions go in here


void main_menu(); // runs in the main loop
void print_main_menu(); // output the main menu description
int get_user_input(); // get a valid integer choice from the user input
void select_menu_item(int input); // run the desired code based on the users choice
void go_back_to_main(); // print message to prompt user to return to main menu
bool is_integer(std::string num); // check input is 

int main(int argc, char const *argv[]) {
  // this will run forever until we hit the exit(1); line in select_menu_item()
  while(1){
    main_menu();
  }
  return 0;
}

void main_menu() {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 4;

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

void select_menu_item(int input) {
  switch (input) {
    case 1:
      dc_to_dc();
      go_back_to_main();
      break;
    case 2:
      menu_item_2();
      go_back_to_main();
      break;
    case 3:
      menu_item_3();
      go_back_to_main();
      break;
    default:
      std::cout << "Bye!\n";
      exit(1);
      break;
  }
}
// Prints the main menu
void print_main_menu() {
  std::cout << "                              .                                                                                   .                   " << std::endl;
  std::cout << "                             --                                                                                  --                   " << std::endl;
  std::cout << "                           :==                                                                                 :==                    " << std::endl;
  std::cout << "                         .-:-                                                                                .-:-                     " << std::endl;
  std::cout << "                       .-..-                                                                               .-..-                      " << std::endl;
  std::cout << "                     .-:..-               -------------------- Main Menu -------------------             .-:..-                       " << std::endl;
  std::cout << "                   .-:...-                |                                                |           .-:...-                        " << std::endl;
  std::cout << "                  ::....::...........     |               1. DC-DC Converter               |          ::....::...........             " << std::endl;
  std::cout << "                :::..............:--      |                                                |        :::..............:--              " << std::endl;
  std::cout << "              :-:...............-:        |               2. AC-DC Rectifier               |      :-:...............-:                " << std::endl;
  std::cout << "             :::::::::::::....:-          |                                                |     :::::::::::::....:-                  " << std::endl;
  std::cout << "                        -:..:-.           |               3. DC-AC Inverter                |                -:..:-.                   " << std::endl;
  std::cout << "                      .-..--              |                                                |              .-..--                      " << std::endl;
  std::cout << "                     :-:-:                |               4. Exit                          |             :-:-:                        " << std::endl;
  std::cout << "                    =---                  |                                                |            =---                          " << std::endl;
  std::cout << "                  .-=-                    --------------------------------------------------          .-=-                            " << std::endl;
  std::cout << "                 .=-                                                                                 .=-                              " << std::endl;
  std::cout << "                ::                                                                                  ::                                " << std::endl;
  std::cout << "               .                                                                                   .                                  " << std::endl;
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
}

//Prints DC-DC converter menu
void print_dc_dc_menu(){
    std::cout << "\n----------- -DC-DC- Converter ------------\n|";
  std::cout << "\t\t\t\t\t|\n|\t1. Buck Converter\t\t|\n|";
  std::cout << "\t\t\t\t\t|\n|\t2. Boost Converter\t\t|\n|";
  std::cout << "\t\t\t\t\t|\n|\t3. Return to Main Menu\t\t|\n|";
  std::cout << "\t\t\t\t\t|\n-----------------------------------------\n";
}

//Prompts the user to select an item in the DC-DC menu
int get_user_input_dc_dc(){
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 3;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {
      input = std::stoi(input_string);
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

void select_menu_item_dc_dc(int input){
  switch (input) {
    case 1:
      converter_input_parameters(1); //Calls function for buck converter
      break;
    case 2:
      converter_input_parameters(2); //Calls function for boost converter
      break;
    default:
      main_menu();
      break;
  }
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}