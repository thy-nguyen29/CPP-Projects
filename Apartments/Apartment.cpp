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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;

namespace sdds
{
    Apartment::Apartment(int number, double balance)
    {

        if (number >= 1000 && number <= 9999
            && balance >= 0)
        {
            m_number = number;
            m_balance = balance;
            isActive = true;
        }
        else {
            m_number = -1;
            m_balance = 0.0;
            isActive = false;
        }

    }

    void Apartment::setInvalid()
    {
        m_number = -1;
        m_balance = 0.0;
        isActive = false;
    }

    std::ostream& Apartment::display() const
    {
        if (*this)
        {
            cout.width(4);
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else
        {
            cout << "Invld|  Apartment   ";
        }
        return cout;
    }

    Apartment::operator bool() const
    {
        return isActive;
    }

    Apartment::operator int() const
    {
        return m_number;
    }

    Apartment::operator double() const
    {
        return m_balance;
    }

    bool Apartment::operator~() const
    {
        return m_balance < 0.00001;
    }

    Apartment& Apartment::operator = (const int val)
    {
        if (this->isActive == true) {
            if (val >= 1000 && val <= 9999)
            {
                this->m_number = val;
            }
            else {
                this->setInvalid();
            }
        }
        return *this;
    }

    Apartment& Apartment::operator = (Apartment& A)
    {
        int temp = this->m_number;
        double tp = this->m_balance;
        this->m_number = A.m_number;
        this->m_balance = A.m_balance;
        A.m_number = temp;
        A.m_balance = tp;
        if (this->m_number < 1000 || this->m_number > 9999 || this->m_balance < 0)
            this->setInvalid();
        else {
            this->isActive = true;
        }

        if (A.m_number < 1000 || A.m_number > 9999 || A.m_balance < 0)
            A.setInvalid();
        else
        {
            A.isActive = true;
        }

        return *this;
    }

    Apartment& Apartment::operator+=(double val)
    {
        if (this->isActive == true && val > 0) {
           
                this->m_balance += val;
        }
        return *this;
    }


    Apartment& Apartment::operator-=(double val)
    {
        if (this->isActive == true && val > 0 && (this->m_balance - val >= 0)) {
            this->m_balance -= val;
        }
        return *this;
    }

    Apartment& Apartment::operator << (Apartment& A)
    {
        if (this->isActive == true && A.isActive == true && (this != &A)) {
            this->m_balance += A.m_balance;
            A.m_balance = 0;
            // A.m_number = 0;
        }
        return *this;
    }

    Apartment& Apartment::operator>>(Apartment& A)
    {
        if (this->isActive == true && A.isActive == true && (this != &A))
        {

            A.m_balance += this->m_balance;
            this->m_balance = 0;
            // this->m_number = 0;
        }
        return *this;
    }

    double operator+(const Apartment& A, const Apartment& B)
    {
        // double sum = 0;
        if (A.isActive == true && B.isActive == true)
        {
            return  A.m_balance + B.m_balance;
        }
        else {
            return 0;
        }
    }

    double operator += (double& val, const Apartment& A) {
        if (A.isActive == true)
        {
            val += double(A);
            return val;
        }
        return val;
    };
}