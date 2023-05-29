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

#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include<iostream>
#include "TourTicket.h"

namespace sdds
{
    class TourBus
    {
    private:
        TourTicket* tickets;
        int noOfPassengers;
    public:
        bool boarded;
        TourBus(const int noOfPassengers);
        ~TourBus();
        int getNoOfPassengers();
        bool validTour() const;
        const TourBus& board();
        void startTheTour() const;
    };
};

#endif
