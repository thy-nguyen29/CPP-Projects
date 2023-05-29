/*
*****************************************************************************
                          Workshop - #10
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 29, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include <iostream>
#include <cstring>
#include "Collection.h"
using namespace std;
namespace sdds{
    template <typename T>
    bool search(T A[], int n, const char* key, Collection<T> &C){
        int count = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == key){
                count++;
                C.add(A[i]);
                C.resize(count);
            }
        }
        return (count > 0);
    }
};
#endif