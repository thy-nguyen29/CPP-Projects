/*
*****************************************************************************
                          Workshop - #8
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 15, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_Line_H
#define SDDS_Line_H
#include "LblShape.h"
namespace sdds{
    class Line : public LblShape{
        private:
            int m_length;
        public:
            Line();
            Line(const char* label, int length);
            void getSpecs(std::istream& is);
            void draw(std::ostream& os)const;
    };
}
#endif