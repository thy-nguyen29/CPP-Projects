/*
*****************************************************************************
                          Workshop - #5 (P1)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Oct 14, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
    class Apartment
    {
       
    public:
        int m_number = -1;
        double m_balance = 0.0;
        bool isActive;
        Apartment(int number, double balance);
        std::ostream& display()const;
        void setInvalid();
        operator bool()const;
        operator int()const;
        operator double() const;
        bool operator~() const;
        Apartment& operator = (const int val);
        Apartment& operator = (Apartment& A);
        Apartment& operator += (double val);
        Apartment& operator -= (double val);
        Apartment& operator << (Apartment& A);
        Apartment& operator >> (Apartment& A);
    };
    double operator+(const Apartment& A, const Apartment& B);
    double operator += (double& val, const Apartment& A);
}

#endif // SDDS_APARTMENT_H_