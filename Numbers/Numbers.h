/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Oct 25, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds
{
    class Numbers
    {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void deallocate();
        void setFilename(const char* filename);
        int numberCount() const;
        bool load();
        void save();
        Numbers& sort(bool ascending);
    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers& N);
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();
        Numbers& operator = (const Numbers& N);
        Numbers operator-() const;
        Numbers operator+() const;
        Numbers& operator+=(double num);
        std::ostream& display(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

