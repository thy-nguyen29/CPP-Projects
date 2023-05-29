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
#include<cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds{
    Rectangle::Rectangle(){
        m_width = 0;
        m_height = 0;
    }
    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label){
        if(height < 3 || width < (int)strlen(label) + 2){
            m_height = 0;
            m_width = 0;
        }else{
            m_height = height;
            m_width = width;
        }
    }
    void Rectangle::getSpecs(std::istream& is){
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore(1000, ',');
        is >> m_height;
        is.ignore(1000, '\n');
    }
    void Rectangle::draw(std::ostream& os)const{
        if (m_width > 0 && m_height > 0 && label() != nullptr){
            //first line
            os << "+";
            for(int i = 0; i < m_width - 2; i++){
                os << "-";
            }
            os << "+";
            os << endl;
            //second line
            os << "|";
            os.width(m_width - 2);
            os.fill(' ');
            os.setf(ios::left);
            os << label();
            os.unsetf(ios::left);
            os << "|";
            os << endl;
            //middle lines
            for(int i = 0; i < m_height - 3; i++){
                os << "|";
                for(int j = 0; j < m_width - 2; j++){
                    os << " ";
                }
                os << "|";
                os << endl;
            }
            //last line
            os << "+";
            for(int i = 0; i < m_width - 2; i++){
                os << "-";
            }
            os << "+";
        }
    }
}