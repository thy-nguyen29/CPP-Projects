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

#ifndef SDDS_WORD_H
#define SDDS_WORD_H
#include <cstring>

namespace sdds
{
    
    const int MAX_DEF_NUM = 8;
    const int MAX_WORD_LENGTH = 64;
    const int MAX_DEF_LENGTH = 1024;
    typedef struct
    {
        char word[MAX_WORD_LENGTH];
        char type[MAX_DEF_NUM][20];
        char definition[MAX_DEF_NUM][MAX_DEF_LENGTH];
        int defNum;
    } Word;


    //=== FUNCTION PROTOTYPES ===//

    void removeNewLineCharacter(char* word);
    void removeColonCharacter(char* word);
}

#endif
