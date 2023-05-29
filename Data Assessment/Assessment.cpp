/*
*****************************************************************************
                          Workshop - #2 (P1)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Sep 22, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Assessment.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

namespace sdds
{

	bool read(int& value, FILE* fptr)
	{
		int test = fscanf(fptr, "%d[^\n]", &value);
		return (test != EOF && test != 0);

	}

	bool read(double& value, FILE* fptr)
	{
		int test = fscanf(fptr, "%lf[^\n]", &value);
		return (test != EOF && test != 0);
	}

	bool read(char* cstr, FILE* fptr)
	{
		int test = fscanf(fptr, ",%60[^\n]\n", cstr);
		return (test != EOF && test != 0);
	}

	bool read(Assessment& asmnt, FILE* fptr)
	{
		double number;
		char title[MAX_TITLE_NUM + 1]{};
		bool test = false;


		if (read(number, fptr) && read(title, fptr))
		{
			int i = 0;
			asmnt.m_mark = new double;
			while (title[i] != '\0')
			{
				i++;
			}

			asmnt.m_title = new char[MAX_TITLE_NUM + 1];
			*asmnt.m_mark = number;
			sdds::strcpy(asmnt.m_title, title, i);
			test = true;
		}

		return test;

	}


	void freeMem(Assessment*& aptr, int size)
	{
		int i{};

		for (i = 0; i < size; i++)
		{
			delete aptr[i].m_mark;
			aptr[i].m_mark = nullptr;
			delete[] aptr[i].m_title;
			aptr[i].m_title = nullptr;

		}

		delete[] aptr;
		aptr = nullptr;
	}

	int read(Assessment*& aptr, FILE* fptr)
	{
		int number{};
		if (read(number, fptr))
		{
			int i{};
			aptr = new Assessment[number];
			while (!feof(fptr))
			{
				read(aptr[i], fptr);
				i++;
			}
			if (i == number)
			{
				return number;
			}
			else
			{
				if (i < number)
				{
					freeMem(aptr, i);
				}

				else
				{
					freeMem(aptr, number);
				}
			}
		}
		else
		{
			return 0;
		}
	}

}

