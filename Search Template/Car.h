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

#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <iostream>
#include "ReadWrite.h"
namespace sdds {
   class Car : public ReadWrite {
      char _plate[9];
      char _makeModel[41];
   public:
      Car(const char* plate = "", const char* makeModel = "");
      void set(const char* plate, const char* makeModel);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(const char* mmSubstr)const;
   };


}
#endif // !SDDS_CAR_H_
