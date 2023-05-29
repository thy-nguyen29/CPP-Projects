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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

const bool APP_OS_WINDOWS = false;
int listMenu();

int listMenu() {
    cout << "-->>> My Shopping List <<<--" << endl;
    displayList();
    cout << "----------------------------" << endl
        << "1- Toggle bought Item" << endl
        << "2- Add Shopping Item" << endl
        << "3- Remove Shopping Item" << endl
        << "4- Remove bought Items" << endl
        << "5- Clear List" << endl
        << "0- Exit" << endl << "> ";
    return readInt(0, 5);
}

int main() {
    bool done = false;
    loadList();
    while (!done) {
        system(APP_OS_WINDOWS ? "cls" : "clear");
        switch (listMenu()) {   
        case 1:
            toggleBought();
            break;
        case 2:
            addItemToList();
            break;
        case 3:
            removeItemfromList();
            break;
        case 4:
            removeBoughtItems();
            break;
        case 5:
            clearList();
            break;
        default:
            done = true;
        }
    }
    saveList();
    return 0;
}
