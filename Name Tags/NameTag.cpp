/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Oct 02, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <cstring>
#include "Utils.h"
#include "NameTag.h"
using namespace std;

namespace sdds{
    void NameTag::set(const char *name)
    {
        int n = sdds::strlen(name);
        if (n <= 50)
        {
            sdds::strcpy(this->name, name, n);
        }
    }

    void NameTag::print()
    {
        int size = sdds::strlen(this->name);
        for (int i = 0; i < size + 4; i++)
        {
            cout << "*";
        }

        cout << endl;
        cout << "* ";
        cout << name;
        cout << " *";
        cout << endl;
        for (int i = 0; i < size + 4; i++)
        {
            cout << "*";
        }
    }

    void NameTag::print(int size)
    {
        int tagSize = sdds::strlen(this->name);
        for(int i = 0; i < size + 4; i++){
            cout << "*";
        }
        cout << endl;

        cout << "* ";
        cout << this->name;
        for (int i = 0; i < size - tagSize; i++){
            cout << " ";
        }

        cout << " *";
        cout << endl;
        for (int i = 0; i < size + 4; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

