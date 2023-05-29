/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Oct 07, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include <fstream>
#include "Seat.h"
using namespace std;
namespace sdds
{
    bool Seat::validate(int row, char letter) const {
        if ((row >= 1 && row <= 4) || (row >= 7 && row <= 15) || (row >= 20 && row <= 38)) {
            if ((row >= 1 && row <= 4)) {
                if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')
                    return true;
            }
            else {
                if (letter >= 'A' && letter <= 'F')
                    return true;
            }
        }
        return false;
    };
    //return reference to the current object
    Seat& Seat::alAndCp(const char* str) {
        seatName = nullptr;
        reset();
        if (str != nullptr && std::strlen(str) > 0) {
            seatName = new char[std::strlen(str) + 1];
            strcpy(seatName, str);
        }
        return *this;
    };

    Seat& Seat::reset() {
       
        delete[] seatName;
        seatName = nullptr;
        
        seatRow = 0;
        seatLetter = 0;
        return *this;
    };

    bool Seat::isEmpty() const {
        if (seatName == nullptr)
            return true;
        else
            return false;
    };

    bool Seat::assigned() const {
        return validate(seatRow, seatLetter);
    };

    Seat::Seat()
    {
        seatName = nullptr;
        reset();
    };

    Seat::Seat(const char* passengerName)
    {
        seatName = nullptr;
        reset();
        alAndCp(passengerName);
        seatRow = 0;
        seatLetter = 0;
    };

    Seat::Seat(const char* passengerName, int row, char letter)
    {
        seatName = nullptr;
        reset();
        alAndCp(passengerName);
        set(row, letter);
    };

    Seat::~Seat()
    {
        if (seatName != nullptr)
        {
            delete[] seatName;
            seatName = nullptr;
        }
    };

    Seat& Seat::set(int row, char letter)
    {
        if (validate(row, letter)) {
            this->seatRow = row;
            this->seatLetter = letter;
        }
        else {
            this->seatRow = 0;
            this->seatLetter = 0;
        }
        return *this;
    };

    int Seat::row() const
    {
        return seatRow;
    };

    char Seat::letter() const
    {
        return seatLetter;
    };

    const char* Seat::passenger() const
    {
        return seatName;
    };

    std::ostream& Seat::display(std::ostream& coutRef) const
    {
        if (isEmpty()) {
            coutRef << "Invalid Seat!";
        }
        else {
            int name_length = std::strlen(seatName);
            if (name_length > 40)
            {
                for (int i = 0; i < 40; i++) {
                    coutRef << seatName[i];
                }
            }
            else
            {
                coutRef << seatName;
                for (int i = 0; i < 40 - name_length; i++) {
                    coutRef << ".";
                }
            }
            coutRef << " ";
            if (seatRow == 0) {
                coutRef << "___";
            }           
            else {
                coutRef << seatRow;
                coutRef << seatLetter;
            }         
        }
        return coutRef;
    };

    std::istream& Seat::read(std::istream& cinRef) {
        
        reset();
        char name[71];
        int row;
        char letter;
        cinRef.getline(name, 71, ',');
        cinRef >> row;
        cinRef >> letter;
        cinRef.ignore(1000, '\n');
        if (!cinRef.fail()) {
            alAndCp(name);
            set(row, letter);
        }
        return cinRef;
    };
}
