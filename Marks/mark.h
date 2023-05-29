/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Oct 17, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include<iostream>
namespace sdds
{
    class Mark
    {
    public:
        int mark;
        bool isValid;
        Mark();
        Mark(int mark);
        operator int() const;
        operator double() const;
        operator char() const;
        operator bool() const;
        bool operator == (const Mark& M) const;
        bool operator != (const Mark& M) const;
        bool operator < (const Mark& M) const;
        bool operator > (const Mark& M) const;
        bool operator <= (const Mark& M) const;
        bool operator >= (const Mark& M) const;
        int operator ++ ();
        int operator ++ (int);
        int operator -- ();
        int operator -- (int);
        bool operator ~() const;
        Mark& operator = (int val);
        Mark& operator = (const Mark& M);
        Mark& operator += (int val);
        Mark& operator -= (int val);
        Mark operator + (int val) const;
        Mark operator + (const Mark& M) const;

        Mark& operator << (Mark& M);
        Mark& operator >> (Mark& M);

    };
    int operator += (int& val, const Mark& M);
    int operator -= (int& val, const Mark& M);
    int operator + (int val, const Mark& M);
}
#endif