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

#include<iostream>
#include "Mark.h"
using namespace std;
namespace sdds
{
    Mark::Mark() {
        mark = 0;
        isValid = true;
    }

    Mark::Mark(int mark) {
        if (mark >= 0 && mark <= 100) {
            this->mark = mark;
            isValid = true;
        }
        else {
            this->mark = 0;
            isValid = false;
        }
    }

    Mark::operator int() const {
        return isValid ? mark : 0;
    }

    Mark::operator double() const {
        if (isValid) {
            if (mark < 50) // 0 <= mark < 50
                return 0;
            if (mark < 60) // 50 <= mark < 60
                return 1.0;
            if (mark < 70) // 60 <= mark < 70
                return 2.0;
            if (mark < 80) // 70 <= mark < 80
                return 3.0;
            return 4.0; // 80 <= mark <= 100 
        }
        else
            return 0;
    }

    Mark::operator char() const {
        if (isValid) {
            if (mark < 50) // 0 <= mark < 50
                return 'F';
            if (mark < 60) // 50 <= mark < 60
                return 'D';
            if (mark < 70) // 60 <= mark < 70
                return 'C';
            if (mark < 80) // 70 <= mark < 80
                return 'B';
            return 'A'; // 80 <= mark <= 100 
        }
        else
            return 'X';
    }

    Mark::operator bool() const {
        return isValid;
    }

    bool Mark::operator == (const Mark& M) const {
        if (this->isValid && M.isValid) {
            return mark == M.mark;
        }
        else {
            return false;
        }
    }

    bool Mark::operator != (const Mark& M) const {
        if (this->isValid && M.isValid) {
            return mark != M.mark;
        }
        else {
            return false;
        }
    }

    bool Mark::operator < (const Mark& M) const {
        if (this->isValid && M.isValid) {
            return mark < M.mark;
        }
        else {
            return false;
        }
    }

    bool Mark::operator > (const Mark& M) const {
        if (this->isValid && M.isValid) {
            return mark > M.mark;
        }
        else {
            return false;
        }
    }

    bool Mark::operator <= (const Mark& M) const {
        if (this->isValid && M.isValid) {
            return mark <= M.mark;
        }
        else {
            return false;
        }
    }

    bool Mark::operator >= (const Mark& M) const {
        if (this->isValid && M.isValid) {
            return mark >= M.mark;
        }
        else {
            return false;
        }
    }

    int Mark::operator ++ () {
        int res = -1;
        if (isValid) {
            mark++;
            if (mark >= 0 && mark <= 100)
            {
                isValid = true;
                res = mark;
            }
            else
            {
                isValid = false;
                mark = 0;
                res = -1;
            }
        }
        return res;
    }

    int Mark::operator ++ (int) {
        int res = -1;
        if (isValid) {
            res = mark;
            mark++;
            if (mark >= 0 && mark <= 100)
            {
                isValid = true;
            }
            else
            {
                isValid = false;
                mark = 0;
            }
        }
        else {
            res = -1;
        }
        return res;
    }

    int Mark::operator -- () {
        int res = -1;
        if (isValid) {
            mark--;
            if (mark >= 0 && mark <= 100) {
                isValid = true;
                res = mark;
            }
            else {
                isValid = false;
                mark = 0;
                res = -1;
            }
        }
        return res;
    }

    int Mark::operator -- (int) {
        int res = -1;
        if (isValid) {
            res = mark;
            mark--;
            if (mark >= 0 && mark <= 100)
            {
                isValid = true;
            }
            else
            {
                isValid = false;
                mark = 0;
            }
        }
        else {
            res = -1;
        }
        return res;
    }

    bool Mark::operator ~() const {
        if (isValid) {
            return (char(*this) == 'F') ? false : true;
        }
        return false;
    }

    Mark& Mark::operator = (int val) {
        if (val >= 0 && val <= 100) {
            mark = val;
            isValid = true;
        }
        else {
            mark = 0;
            isValid = false;
        }
        return *this;
    }

    Mark& Mark::operator=(const Mark& M) {
        if (this != &M) {
            if (M.isValid) {
                mark = M.mark;
                isValid = true;
            }
            else {
                mark = 0;
                isValid = false;
            }
        }
        return *this;
    }

    Mark& Mark::operator += (int val) {
        if (isValid) {
            if (mark + val <= 100) {
                mark += val;
            }
            else {
                mark = 0;
                isValid = false;
            }
        }
        return *this;
    }

    Mark& Mark::operator -= (int val) {
        if (isValid) {
            if (mark - val >= 0) {
                mark -= val;
            }
            else {
                mark = 0;
                isValid = false;
            }
        }
        return *this;
    }

    Mark Mark::operator + (int val) const {
        Mark temp = *this;
        if (isValid) {
            temp.mark += val;
            if (temp.mark >= 0 && temp.mark <= 100) {
                temp.isValid = true;
            }
            else
            {
                temp.isValid = false;
                temp.mark = 0;
            }
        }
        return temp;
    }

    Mark Mark::operator+(const Mark& M) const {
        Mark temp = *this;
        if (isValid && M.isValid) {
            temp.mark += M.mark;
            if (temp.mark >= 0 && temp.mark <= 100) {
                temp.isValid = true;
            }
            else
            {
                temp.isValid = false;
                temp.mark = 0;
            }
        }
        return temp;
    };

    int operator += (int& val, const Mark& M) {
        if (M.isValid) {
            val += M.mark;
        }
        return val;
    }

    int operator -= (int& val, const Mark& M) {
        if (M.isValid) {
            val -= M.mark;
        }
        return val;
    }

    Mark& Mark::operator<<(Mark& M) {
        if (isValid && M.isValid) {
            this->mark += M.mark;
            M.mark = 0;
            if (this->mark >= 0 && this->mark <= 100) {
                this->isValid = true;
            }
            else {
                this->isValid = false;
                this->mark = 0;
            }
        }
        return *this;
    }

    Mark& Mark::operator>>(Mark& M)
    {
        if (isValid && M.isValid) {
            M.mark += this->mark;
            this->mark = 0;
            if (M.mark >= 0 && M.mark <= 100) {
                M.isValid = true;
            }
            else {
                M.isValid = false;
                M.mark = 0;
            }
        }
        return *this;
    }

    int operator+(int val, const Mark& M) {
        return  val + M.mark;
    }
}