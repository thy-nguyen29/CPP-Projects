/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Sep 25, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include <cstdio>
namespace sdds
{
    const int MAX_POSTAL_CODE = 3;
    struct Postal
    {
        char* code;
        int* population;
    };

    bool read(int& value, FILE* fptr);
    bool read(char* cstr, FILE* fptr);
    bool read(Postal& pt, FILE* fptr);
    void display();
    void deallocateMemory();
    bool load(char const* filename);

}
#endif // SDDS_POPULATION_H_