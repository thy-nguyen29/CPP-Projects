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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "dictionary.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	const int MAX_OF_RECS = 100;
	Word rec[MAX_OF_RECS] = {};
    Dictionary dictionary;

    int LoadDictionary(const char* filename)
    {
        dictionary.size = 0;
        FILE* fp = fopen(filename, "r");
        if (fp == nullptr)
        {
           
            return 1;
        }
        else
        {
          
            int i = 0;
            while (fscanf(fp, "%s", dictionary.words[i].word) != EOF)
            {
                fgetc(fp);
                int j = 0;

                while (fgetc(fp) == '\t')
                {
                    fscanf(fp, "%s", dictionary.words[i].type[j]);
                    removeColonCharacter(dictionary.words[i].type[j]);
                    fgetc(fp);
                    fgets(dictionary.words[i].definition[j], 1024, fp);
                    removeNewLineCharacter(dictionary.words[i].definition[j]);
                    j++;
                }

                dictionary.words[i].defNum = j;
                i++;
            }
            dictionary.size = i;
            fclose(fp);

            return 0;
        }
    }

	
    void SaveDictionary(const char* filename)
    {
        FILE* fp = fopen(filename, "w");
        int i = 0;
        while (i < dictionary.size)
        {
            fprintf(fp, "%s\n", dictionary.words[i].word);
            for (int j = 0; j < dictionary.words[i].defNum; j++)
            {
                fprintf(fp, "\t%s: %s\n", dictionary.words[i].type[j], dictionary.words[i].definition[j]);
            }
            i++;
            fprintf(fp, "\n");
        }
        fclose(fp);
    }

    void DisplayWord(const char* word)
    {
        
        for (int i = 0; i < dictionary.size; i++)
        {
            if (strcmp(word, dictionary.words[i].word) == 0)
            {
                printf("FOUND: [%s] has [%d] definitions:\n", word, dictionary.words[i].defNum);
                for (int j = 0; j < dictionary.words[i].defNum; j++)
                {
                    printf("%d. {%s} %s\n", j + 1, dictionary.words[i].type[j], dictionary.words[i].definition[j]);
                }
                return;
            }
        }

        printf("NOT FOUND: word [%s] is not in the dictionary.\n", word);
        return;
    }

    void AddWord(const char* word, const char* type, const char* definition)
    {
        for (int i = 0; i < dictionary.size; i++)
        {
            if (strcmp(word, dictionary.words[i].word) == 0)
            {
                for (int j = 0; j < dictionary.words[i].defNum; j++)
                {
                    if (strcmp(type, dictionary.words[i].type[j]) == 0 && strcmp(type, dictionary.words[i].definition[j]) == 0)
                        return;
                }
                dictionary.words[i].defNum++;
                strcpy(dictionary.words[i].type[dictionary.words[i].defNum - 1], type);
                strcpy(dictionary.words[i].definition[dictionary.words[i].defNum - 1], definition);
                return;
            }
        }

        dictionary.size++;
        strcpy(dictionary.words[dictionary.size - 1].word, word);
        dictionary.words[dictionary.size - 1].defNum = 1;
        strcpy(dictionary.words[dictionary.size - 1].type[0], type);
        strcpy(dictionary.words[dictionary.size - 1].definition[0], definition);
        return;
    }

    int UpdateDefinition(const char* word, const char* type, const char* definition)
    {
        for (int i = 0; i < dictionary.size; i++)
        {
            if (strcmp(word, dictionary.words[i].word) == 0)
            {
                if (dictionary.words[i].defNum > 1)
                {
                    printf("The word [%s] has multiple definitions:\n", word);
                    for (int j = 0; j < dictionary.words[i].defNum; j++)
                    {
                        printf("%d. {%s} %s\n", j + 1, dictionary.words[i].type[j], dictionary.words[i].definition[j]);
                    }
                    cout << "Which one to update? ";
                    int tp;
                    cin >> tp;
                    strcpy(dictionary.words[i].type[tp - 1], type);
                    strcpy(dictionary.words[i].definition[tp - 1], definition);
                    return 1;
                }
            }
        }
        return 0;
    }
}




