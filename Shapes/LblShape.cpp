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
#include "LblShape.h"
using namespace std;
namespace sdds{
    LblShape::LblShape(){
        m_label = nullptr;
    }
    LblShape::LblShape(const char* label){
        m_label = nullptr;
        if(label != nullptr){
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }
    LblShape::~LblShape(){
        delete[] m_label;
        m_label = nullptr;
    }
    const char* LblShape::label()const{
        return m_label;
    }
    void LblShape::getSpecs(std::istream& is){
        char label[101];
        is.get(label, 101, ',');
        is.ignore(1000, ',');
        delete[] m_label;
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }
}