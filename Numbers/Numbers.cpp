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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Numbers.h"
using namespace std;
namespace sdds
{
    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;

    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            deallocate();
            setEmpty();
            m_isOriginal = false;
        }
    }

    Numbers::Numbers(const Numbers& N) {
        setEmpty();
        m_isOriginal = false;
        *this = N;
    }

    Numbers& Numbers::operator=(const Numbers& N) {
        if (this != &N) {
            delete[] m_numbers;
            delete[] m_filename; // deallocate the file name
            setEmpty();
            m_isOriginal = false;
            m_numbers = new double[N.m_numCount];
            m_filename = new char[strlen(N.m_filename) + 1]; // copy new file name
            strcpy(m_filename, N.m_filename);                // copy new file name
            this->m_numCount = N.m_numCount;
            for (int i = 0; i < N.m_numCount; i++) {
                m_numbers[i] = N.m_numbers[i];
            }
        }
        return *this;
    }

    Numbers& Numbers::sort(bool ascending) {
        int i, j;
        double temp;
        for (i = 0; i < m_numCount - 1; i++) {
            for (j = 0; j < m_numCount - i - 1; j++) {
                if (ascending) {
                    if (m_numbers[j] > m_numbers[j + 1]) {
                        temp = m_numbers[j];
                        m_numbers[j] = m_numbers[j + 1];
                        m_numbers[j + 1] = temp;
                    }
                }
                else {
                    if (m_numbers[j] < m_numbers[j + 1]) {
                        temp = m_numbers[j];
                        m_numbers[j] = m_numbers[j + 1];
                        m_numbers[j + 1] = temp;
                    }
                }
            }
        }
        return *this;
    }

    Numbers::~Numbers() {
        save();
        deallocate();
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Numbers::deallocate() {
        delete[] m_filename;
        delete[] m_numbers;
    }

    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }

    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    int Numbers::numberCount() const
    {
        ifstream file(m_filename);
        int ct = 0;
        if (file)
        {
            double num;
            while (file >> num)
            {
                ct++;
            }
        }
        file.close();
        return ct;
    }

    bool Numbers::load() {
        bool ok = false;
        ifstream file(m_filename);
        if (file) {
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++) {
                file >> m_numbers[i];
            }
            ok = true;
        }
        file.close();
        return ok;
    }

    void Numbers::save() {
        if (m_isOriginal && !isEmpty()) {
            ofstream file(m_filename);
            if (file) {
                for (int i = 0; i < m_numCount; i++) {
                    file << fixed << setprecision(2) << m_numbers[i] << '\n';
                }
            }
            file.close();
        }
    }

    Numbers& Numbers::operator+=(double num)
    {
        double* temp = new double[m_numCount + 1];
        for (int i = 0; i < m_numCount; i++) {
            temp[i] = m_numbers[i];
        }
        temp[m_numCount] = num;
        delete[] m_numbers;
        m_numbers = temp;
        m_numCount++;
        return *this;
    }

    std::ostream& Numbers::display(std::ostream& ostr) const
    {
        if (isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << "=========================" << endl;
            if (m_isOriginal) {
                ostr << this->m_filename << endl;
            }
            else {
                ostr << "*** COPY ***" << endl;
            }
            for (int i = 0; i < m_numCount - 1; i++) {
                // the double numbers are printed with two digits after the decimal point.
                ostr << fixed << setprecision(2) << m_numbers[i] << ", ";
            }

            ostr << fixed << setprecision(2) << m_numbers[m_numCount - 1] << endl;

            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << fixed << setprecision(2) << this->max() << endl;
            ostr << "Smallest number: " << fixed << setprecision(2) << this->min() << endl;
            ostr << "Average:         " << fixed << setprecision(2) << this->average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }

    Numbers Numbers::operator-() const
    {
        Numbers N = *this;
        N.sort(false);
        return N;
    }

    Numbers Numbers::operator+() const
    {
        Numbers N = *this;
        N.sort(true);
        return N;
    }

    std::ostream& operator<<(std::ostream& os, const Numbers& N) {
        return N.display(os);
    }

    std::istream& operator>>(std::istream& istr, Numbers& N) {
        double num;
        istr >> num;
        N += num;
        return istr;
    }
}
