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

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Line.h"
using namespace std;
namespace sdds{
    Line::Line(){
        m_length = 0;
    }
    Line::Line(const char* label, int length) : LblShape(label){
        m_length = length;
    }
    void Line::getSpecs(std::istream& is){
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }
    void Line::draw(std::ostream& os)const{
        if (m_length > 0 && label() != nullptr){
            os.width(m_length);
            os.fill('=');
            os.setf(ios::left);
            os << label();
            os.unsetf(ios::left);
        }
    }
    
}