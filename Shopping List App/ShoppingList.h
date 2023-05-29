/*
*****************************************************************************
						  Workshop - #1 (P1)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Sep 13, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_SHOPPINGLIST_H 
#define SDDS_SHOPPINGLIST_H

namespace sdds
{
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

}

#endif
