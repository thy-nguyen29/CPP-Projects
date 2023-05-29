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

#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "ReadWrite.h"
namespace sdds {
   class Employee : public ReadWrite {
      int _empno;
      char _name[41];
      double _salary;
   public:
      Employee();
      Employee(int stno, const char* name, double salary);
      void set(int stno, const char* name, double salary);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(const char* nameSubstr)const;
   };


}
#endif // !SDDS_EMPLOYEE_H_