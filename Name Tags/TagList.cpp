/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Oct 02, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include<iostream>
#include "TagList.h"
#include "Utils.h"

using namespace std;
namespace sdds 
{
    void TagList::set()
    {
        this->numTags = 0;
        this->longestTag = 0;
        this->NameTags = nullptr;
    }

    void TagList::set(int num)
    {
        this->longestTag = 0;
        this->NameTags = new NameTag[num];
    }

    void TagList::add(const NameTag &nt)
    {
        this->NameTags[this->numTags] = nt;
        this->numTags++;
    }

    void TagList::print()
    {
        int longestTag = 0;
        for(int i = 0; i < this->numTags; i++){
            int length = sdds::strlen(this->NameTags[i].getName());

            if (longestTag < length)
            {
                longestTag = length;
            }
        }
        for (int i = 0; i < this->numTags; i++)
        {
            this->NameTags[i].print(longestTag);
        }
    }

    void TagList::cleanup()
    {
        delete[] this->NameTags;
        this->set();
    }
}