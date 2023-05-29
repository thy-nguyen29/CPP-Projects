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
#include "Shape.h"
using namespace std;
namespace sdds{
    std::ostream& operator<<(std::ostream& os, const Shape& s){
        s.draw(os);
        return os;
    }
    Shape::~Shape(){
    }
    std::istream& operator>>(std::istream& is, Shape& s){
        s.getSpecs(is);
        return is;
    }
}