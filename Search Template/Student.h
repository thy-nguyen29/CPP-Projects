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


#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "ReadWrite.h"
#include <iostream>

namespace sdds {
   class Student : public ReadWrite {
      int _stno;
      char _name[41];
   public:
      Student();
      Student(int stno, const char* name);
      void set(int stno, const char* name);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(const char* nameSubstr)const;
   };
}
#endif // !SDDS_STUDENT_H_

