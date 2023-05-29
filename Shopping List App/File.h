/*
*****************************************************************************
						  Workshop - #1 (P1)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date:  Sep 13, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds
{
	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
	
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif