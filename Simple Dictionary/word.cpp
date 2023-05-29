/*
*****************************************************************************
                          Workshop - #1 (P2)
Full Name     : Ngoc Diem Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Sep 19, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "word.h"

using namespace std;
using namespace sdds;

namespace sdds
{

    void removeNewLineCharacter(char* word)
    {
        int i = 0;
        while (word[i] != '\n')
            i++;
        word[i] = '\0';
    }

    void removeColonCharacter(char* word)
    {
        int i = 0;
        while (word[i] != ':')
            i++;
        word[i] = '\0';
    }

}