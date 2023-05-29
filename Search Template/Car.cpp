/*
*****************************************************************************
                          Workshop - #10
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 29, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Car.h"
using namespace std;
namespace sdds {
   Car::Car(const char* plate , const char* makeModel ) {
      set(plate, makeModel);
   }
   void Car::set(const char* plate, const char* makeModel) {
      strncpy(_plate, plate, 8);
      _plate[8] = 0;
      strncpy(_makeModel, makeModel, 40);
      _makeModel[40] = 0;;
   }
   std::ostream& Car::display(std::ostream& os)const {
      return os << _plate << " " << _makeModel;
   }
   std::istream& Car::read(std::istream& is) {
      is >> _plate;
      is.getline(_makeModel, 40, '\n');
      return is;
   }
   bool Car::operator==(const char* mmSubstr)const {
      return strstr(_makeModel, mmSubstr) != nullptr;
   }
}