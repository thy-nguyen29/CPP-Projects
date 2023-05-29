/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Sep 29, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CC_H_
#define SDDS_CC_H_
#include<iostream>

namespace sdds {
    class CC{
        public:
            char *name;
            short cvv, expMon, expYear;
            unsigned long long cardNo;

    private:
        bool validate(const char *name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
        void prnNumber() const;

    public:
        void set();
        void cleanUp();
        bool isEmpty() const;
        void set(const char *cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
        bool read();
        void display(int row = 0) const;
    };
}
#endif