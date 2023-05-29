/*
Name: Thy Nguyen
Email: nnguyen90@myseneca.ca
Student ID: 105310221
Date: Nov 10, 2022
Section: NFF
*/
#include <iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
    Dumper::Dumper(const char* plate, int year, double capacity, const char* address) : VehicleBasic(plate, year) {
        d_capacity = capacity;
        d_load = 0;
        this->NewAddress(address);
    }
    bool Dumper::loaddCargo(double cargo) {
        if (d_load + cargo <= d_capacity) {
            d_load += cargo;
            return true;
        }
        return false;
    }
    bool Dumper::unloadCargo() {
        if (d_load > 0) {
            d_load = 0;
            return true;
        }
        return false;
    }
    std::ostream& Dumper::write(std::ostream& os) {
        VehicleBasic::write(os);
        os << " | " << d_load << "/" << d_capacity;
        return os;
    }
    std::istream& Dumper::read(std::istream& in) {
        VehicleBasic::read(in);
        cout << "Capacity: ";
        in >> d_capacity;
        cout << "Cargo: ";
        in >> d_load;
        return in;
    }
    std::ostream& operator<<(std::ostream& os, Dumper d) {
        d.write(os);
        return os;
    }
    std::istream& operator>>(std::istream& in, Dumper& d) {
        d.read(in);
        return in;
    }

	
}

