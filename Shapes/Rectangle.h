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

#ifndef SDDS_Rectangle_H
#define SDDS_Rectangle_H
#include "LblShape.h"
namespace sdds{
    class Rectangle : public LblShape{
        private:
            int m_width;
            int m_height;
        public:
            Rectangle();
            Rectangle(const char* label, int width, int height);
            void getSpecs(std::istream& is);
            void draw(std::ostream& os)const;
    };
}
#endif