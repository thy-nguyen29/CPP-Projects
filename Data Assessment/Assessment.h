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

#ifndef SDDS_ASSESSMENTS_H_
#define SDDS_ASSESSMENTS_H_
#include <cstdio>

namespace sdds
{

	const int MAX_TITLE_NUM = 60;

	struct Assessment
	{
		double* m_mark;
		char* m_title;
	};

	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);
	bool read(Assessment& asmnt, FILE* fptr);
	void freeMem(Assessment*& aptr, int size);
	int read(Assessment*& aptr, FILE* fptr);

}



#endif