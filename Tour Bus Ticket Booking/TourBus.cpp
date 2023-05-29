/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Oct 10, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include<iostream>
#include "TourTicket.h"
#include "TourBus.h"
using namespace std;
namespace sdds
{
    TourBus::TourBus(const int noOfPassengers) {
        tickets = new TourTicket[noOfPassengers];
        this->noOfPassengers = noOfPassengers;
        this->boarded = false;
    };

    TourBus::~TourBus() {
        delete[] tickets;
        tickets = nullptr;
        noOfPassengers = 0;
        boarded = false;
    };

    int TourBus::getNoOfPassengers()
    {
        return noOfPassengers;
    }

    bool TourBus::validTour() const
    {
        int n = this->noOfPassengers;
        return n == 4 || n == 16 || n == 22;
    };

    const TourBus& TourBus::board()
    {
        this->boarded = true;
        printf("Boarding %d Passengers:\n", this->noOfPassengers);
        char str[41];
        for (int i = 0; i < this->noOfPassengers; i++) {
            printf("%d/%d- Passenger Name: ", i + 1, this->noOfPassengers);
            cin.getline(str, 40, '\n');
            this->tickets[i].issue(str);
        }
        return *this;
    };


    void TourBus::startTheTour() const {
        if (this->validTour() && this->boarded == true) {
            cout << "Starting the tour...." << endl;
            cout << "Passenger List:" << endl;
            cout << "|Row | Passenger Name                           | Num |" << endl;
            cout << "+----+------------------------------------------+-----+" << endl;
            for (int i = 0; i < noOfPassengers; i++) {
                cout << "| ";
                cout.width(2);
                cout.fill(' ');
                cout.unsetf(ios::right);
                cout << i + 1;
                cout << " ";
                this->tickets[i].display();
                cout << endl;
            }
            cout << "+----+------------------------------------------+-----+" << endl;
        }
        else {
            cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
        }

    };
}
