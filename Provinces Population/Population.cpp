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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"
using namespace std;
using namespace sdds;
namespace sdds
{
    extern FILE* fptr;
    Postal* postalList;
    int noOfRecs = 0;

    bool read(int& value, FILE* fptr)
    {
        int res = fscanf(fptr, ",%d[^\n]", &value);
        if (res != EOF and res != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    bool read(char* cstr, FILE* fptr)
    {
        int res = fscanf(fptr, "\n%3[^,]\n", cstr);
        if (res != EOF and res != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    bool read(Postal& pt, FILE* fptr)
    {
        int value;
        char str[MAX_POSTAL_CODE + 1];
        if (read(str, fptr) && read(value, fptr))
        {
            pt.population = new int;
            pt.code = new char[MAX_POSTAL_CODE + 1];
            *pt.population = value;
            strcpy(pt.code, str);
            return true;
        }
        else
        {
            return false;
        }
    };

    void deallocateMemory() {
        for (int i = 0; i < noOfRecs; i++) {
            delete[] postalList[i].code;
            postalList[i].code = nullptr;
            delete postalList[i].population;
        }
        delete[] postalList;
        postalList = nullptr;
    };
  
    bool load(char const* filename)
    {
        if (openFile(filename))
        {
            noOfRecs = noOfRecords();
            postalList = new Postal[noOfRecs];
            for (int i = 0; i < noOfRecs; i++)
            {
                if (read(postalList[i], sdds::fptr) == 0) {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
                    return false;
                }
            }
            closeFile();
            return true;
        }
        else {
            cout << "Could not open data file: " << filename << endl;
            return false;
        }

    };
   
    void display() {
        cout << "Postal Code: population\n";
        cout << "-------------------------\n";
        int const size_arr = noOfRecs;
        int* vst = new int[size_arr];
        for (int i = 0; i < noOfRecs; i++)
        {
            vst[i] = 0;
        }
        int check = 1;
        int idx;
        int ct = 1;
        int sum = 0;
        while (check == 1) {
            idx = -1;
            check = 0;
            for (int i = 0; i < noOfRecs; i++)
            {
                if (vst[i] == 0)
                {

                    check = 1;
                    if (idx == -1)
                    {
                        idx = i;
                    }
                    else
                    {
                        if (*postalList[idx].population > *postalList[i].population)
                        {
                            idx = i;
                        }
                    }
                }
            }
            if (check == 1) {
                vst[idx] = 1;
                cout << ct << "- " << postalList[idx].code << ":  " << *postalList[idx].population << endl;
                sum += *postalList[idx].population;
                ct++;
            }
        }
        cout << "-------------------------\n";
        cout << "Population of Canada: " << sum << endl;;
    };
}