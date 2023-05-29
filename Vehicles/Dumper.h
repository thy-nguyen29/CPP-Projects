/*
Name: Thy Nguyen
Email: nnguyen90@myseneca.ca
Student ID: 105310221
Date: Nov 10, 2022 
Section: NFF
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
    class Dumper : public VehicleBasic
    {
    private:
        double d_capacity;
        double d_load; //current cargo
    public:
        Dumper(const char* plate, int year, double capacity, const char* address);
        bool loaddCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os);
        std::istream& read(std::istream& in);
    };
    std::ostream& operator <<(std::ostream& os, Dumper d);
    std::istream& operator >>(std::istream& in, Dumper& d);
	
}
#endif

