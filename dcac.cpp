#include <string>
#include <iostream>
#include <cmath>
#include <regex> // needed to parse inputs

#include "dcac.h"

// Global variables
DCAC::DCAC() {}
DCAC bipolar;
DCAC unipolar;

bool is_integer(std::string num); // check input is an integer
bool is_float(std:: string num); // check input is a float

void sub_menu_item_1() {
  int val_input;
  std::cout << "\nThis DC-AC inverter uses Bipolar PWM modulation to output an AC voltage\n";
  do {
    bi_display();
    val_input = input_choice();
    change_bi_input_value(val_input);
  } while(val_input != 6);
}
void sub_menu_item_2() {
  int val_input;
  std::cout << "\nThis DC-AC inverter uses Unipolar PWM modulation to output an AC voltage\n";
  do {
    uni_display();
    val_input = input_choice();
    change_uni_input_value(val_input);
  } while(val_input != 6);
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
      std::cout << "\nEnter an integer\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "\nInvalid menu item\n";
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
      std::cout << "\nReturning to Main Menu\n";
      break;
  }
}

// Inverter functions
int input_choice() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 6;

  do {
    std::cout << "\nEnter the number of the value you wish to change: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "\nEnter an integer\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "\nInvalid menu item\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

// Bipolar values
void change_bi_input_value(int val_input) {
  switch (val_input) {
    case 1:
      bipolar.set_Vi();
      break;
    case 2:
      bipolar.set_ma();
      break;
    case 3:
      bipolar.set_bi_efficiency();
      break;
    case 4:
      bipolar.set_f();
      sub_menu_item_2();
      break;
    case 5:
      bipolar.set_L();
      break;
    default:
      std::cout << "\nReturning to Main Menu\n";
      break;
  }
}

// Bipolar sub-menu display
void bi_display() {
  bipolar.get_VAB();
  bipolar.get_Vo();
  bipolar.get_Io();
  bipolar.get_L();
  bipolar.get_theta();
  std::cout << "\n-------------------------------------------------------Inputs--------------------------------------------------------\n";
  std::cout << "\n1. Vi = " << bipolar.get_Vi() << "V\t2. ma = " << bipolar.get_ma() << "\t3. Efficiency = "
            << bipolar.get_efficiency() << "%\t4. Frequency = " << bipolar.get_f() << "Hz\t 5. Inductor = "
            << bipolar.get_L() << "mH\t6. Main Menu\n";
  std::cout << "\n-------------------------------------------------------Outputs-------------------------------------------------------\n";
  std::cout << "\n vo(t) = " << bipolar.get_Vo()*sqrt(2) << " sin(" << 2*PI*bipolar.get_f() << "t - "
            << bipolar.get_theta() << ")\n";
  std::cout << "\n Io = " << bipolar.get_Io() << " A\n";
  std::cout << "\n R = " << bipolar.get_R() << " Ohm(s)\n";
  std::cout << "\n P = " << bipolar.get_P() << " W\n";
  std::cout << "\n---------------------------------------------------------------------------------------------------------------------\n";
}

// Unipolar values
void change_uni_input_value(int val_input) {
  switch (val_input) {
    case 1:
      unipolar.set_Vi();
      break;
    case 2:
      unipolar.set_ma();
      break;
    case 3:
      unipolar.set_uni_efficiency();
      break;
    case 4:
      unipolar.set_f();
      sub_menu_item_2();
      break;
    case 5:
      unipolar.set_L();
      break;
    default:
      std::cout << "\nReturning to Main Menu\n";
      break;
  }
}

// Unipolar Display
// Bipolar sub-menu display
void uni_display() {
  unipolar.get_VAB();
  unipolar.get_Vo();
  unipolar.get_Io();
  unipolar.get_L();
  unipolar.get_theta();
  std::cout << "\n-------------------------------------------------------Inputs--------------------------------------------------------\n";
  std::cout << "\n1. Vi = " << unipolar.get_Vi() << "V\t2. ma = " << unipolar.get_ma() << "\t3. Efficiency = "
            << unipolar.get_efficiency() << "%\t4. Frequency = " << unipolar.get_f() << "Hz\t 5. Inductor = "
            << unipolar.get_L() << "mH\t6. Main Menu\n";
  std::cout << "\n-------------------------------------------------------Outputs-------------------------------------------------------\n";
  std::cout << "\n vo(t) = " << unipolar.get_Vo()*sqrt(2) << " sin(" << 2*PI*unipolar.get_f() << "t - "
            << unipolar.get_theta() << ")\n";
  std::cout << "\n Io = " << unipolar.get_Io() << " A\n";
  std::cout << "\n R = " << unipolar.get_R() << " Ohm(s)\n";
  std::cout << "\n P = " << unipolar.get_P() << " W\n";
  std::cout << "\n---------------------------------------------------------------------------------------------------------------------\n";
}

// DCAC class mutators and accessors
void DCAC::set_Vi() {
  float Vi;
  std::string Vi_string;
  bool valid_input = false;
  std::cout << "\nEnter a new value for the input DC voltage (in volts): ";
  do {
    std::cin >> Vi_string;
    valid_input = is_float(Vi_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "\nEnter a number: ";
    } else {  // if it is an int, check whether in range
      Vi = std::stof(Vi_string);  // convert to int
      if (Vi < 0) {
        std::cout << "\nEnter a postive value: ";
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
  std::cout << "\nEnter a new value for the modulation index: ";
  do {
    std::cin >> ma_string;
    valid_input = is_float(ma_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "\nEnter a number: ";
    } else {  // if it is an float, check whether in range
      ma = std::stof(ma_string);  // convert to float
      if (ma >= 0 && ma <= 1) {
        valid_input = true;
      } else {
        std::cout << "\nEnter a value between 0 and 1: ";
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
  std::cout << "\n(Typical efficiency percentages for a bipolar inverter range from 75-85%.)"
            <<"\nEnter a new value for the Inverter efficiency: ";
  do {
    std::cin >> efficiency_string;
    valid_input = is_float(efficiency_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "\nEnter a number: ";
    } else {  // if it is a float, check whether in range
      efficiency = std::stof(efficiency_string);  // convert to float
      if (efficiency >= 75 && efficiency <= 85) {
        valid_input = true;
      } else {
        std::cout << "\nEnter a value between 75 and 85: ";
        valid_input = false;
        }
    }
  } while (valid_input == false);
  _efficiency = efficiency;
}

void DCAC::set_uni_efficiency() {
  float efficiency;
  std::string efficiency_string;
  bool valid_input = false;
  std::cout << "\n(Typical efficiency percentages for a unipolar inverter range from 85-95%.)"
            << "\nEnter a new value for the Inverter efficiency (in %): ";
  do {
    std::cin >> efficiency_string;
    valid_input = is_float(efficiency_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "\nEnter a number: ";
    } else {  // if it is a float, check whether in range
      efficiency = std::stof(efficiency_string);  // convert to float
      if (efficiency >= 85 && efficiency <= 95) {
        valid_input = true;
      } else {
        std::cout << "\nEnter a value between 85 and 95: ";
        valid_input = false;
        }
    }
  } while (valid_input == false);
  _efficiency = efficiency;
}

void DCAC::set_f() {
  float f;
  std::string f_string;
  bool valid_input = false;
  std::cout << "\nEnter a new value for the frequency (in hertz): ";
  do {
    std::cin >> f_string;
    valid_input = is_float(f_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "\nEnter a number: ";
    } else {  // if it is an float, check whether in range
      f = std::stof(f_string);  // convert to float
      if (f > 0) {
        valid_input = true;
      } else {
        std::cout << "\nEnter a value greater than 0: ";
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
  std::cout << "\n(Typical inductor values range from 10-50mH)";
  std::cout << "\nEnter a new value for the inductor (in milli Henry): ";
  do {
    std::cin >> L_string;
    valid_input = is_float(L_string);
    // if input is not an float, print an error message
    if (valid_input == false) {
      std::cout << "\nEnter a number: ";
    } else {  // if it is an float, check whether in range
      L = std::stof(L_string);  // convert to float
      if (0 < L && L <= 50) {
        valid_input = true;
      } else if (L > 50) {
        std::cout << "\nEnter a value less than 50mH: ";
        valid_input = false;
        } else {
          std::cout << "\nEnter a positive value: ";
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

float DCAC::get_efficiency() {
  return _efficiency;
}

float DCAC::get_f() {
  return _f;
}

float DCAC::get_L() {
  return _L;
}

float DCAC::get_VAB() {
  float VAB;
  VAB = (_Vi * _ma) / sqrt(2);
  _VAB = VAB;
  return _VAB;
}

float DCAC::get_Vo() {
  float Vo;
  Vo = _VAB * (_efficiency/100);
  _Vo = Vo;
  return _Vo;
}

float DCAC::get_Io() {
  float Io;
  float sqr_Vo = pow(_Vo, 2);
  float sqr_VAB = pow(_VAB, 2);
  float Xf = 2 * PI * (_L * pow(10, -3)) * _f;
  float sqr_Xf = pow(Xf, 2);
  Io = sqrt((sqr_VAB - sqr_Vo) / sqr_Xf);
  _Io = Io;
  return _Io;
}

float DCAC::get_theta() {
  float theta;
  float Xf = 2 * PI * (_L * pow(10, -3)) * _f;
  float angle = (Xf * _Io) / (_Vo);
  theta = atan(angle) * (180 / PI);
  _theta = theta;
  return _theta;
}

float DCAC::get_R() {
  float R;
  R = _Vo / _Io;
  _R = R;
  return _R;
}

float DCAC::get_P() {
  float P;
  P = _Vo * _Io;
  _P = P;
  return _P;
}

// https://stackoverflow.com/questions/12643009/regular-expression-for-floating-point-numbers
bool is_float(std::string num) {
  return std::regex_match(num, std::regex("[+-]?([0-9]*[.])?[0-9]+"));
}