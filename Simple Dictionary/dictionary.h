/*
*****************************************************************************
                          Workshop - #1 (P2)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Sep 19, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include <cstring>
#include "word.h"

namespace sdds
{
    const int MAX_WORD_NUM = 100;
    typedef struct
    {
        Word words[MAX_WORD_NUM];
        int size = 0;
    } Dictionary;
   
   //=== FUNCTION PROTOTYPES ===//

    int LoadDictionary(const char* filename);
    void SaveDictionary(const char* filename);
    void DisplayWord(const char* word);
    void AddWord(const char* word, const char* type, const char* definition);
    int UpdateDefinition(const char* word, const char* type, const char* definition);
}
#endif
