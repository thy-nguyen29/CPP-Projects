/*
Name: Thy Nguyen
Email: nnguyen90@myseneca.ca
Student ID: 105310221
Date: Nov 10, 2022
Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	VehicleBasic::VehicleBasic(const char* plate, int year) {
		strcpy(v_plate, plate);
		v_year = year;
		strcpy(this->v_address, "Factory");
	}

	void VehicleBasic::NewAddress(const char* address) {
		if (strcmp(this->v_address, address) != 0) {
			cout << "|";
			cout.fill(' ');
			cout.width(8);
			cout.setf(ios::right);
			cout << v_plate;
			cout << "| |";
			cout.width(20);
			cout << v_address;

			cout.unsetf(ios::right);
			cout << " ---> ";

			cout.setf(ios::left);
			cout.width(20);
			cout << address;
			cout << "|" << endl;
			strcpy(this->v_address, address);
		}
	}
	std::ostream& VehicleBasic::write(std::ostream& os) {
		os << "| " << v_year << " | " << v_plate << " | " << v_address;
		return os;
	}
	std::istream& VehicleBasic::read(std::istream& in) {
		cout << "Built year: ";
		in >> v_year;
		cout << "License plate: ";
		in >> v_plate;
		cout << "Current location: ";
		in >> v_address;
		return in;
	}

	std::ostream& operator <<(std::ostream& os, VehicleBasic v) {
		v.write(os);
		return os;
	};

	std::istream& operator >>(std::istream& in, VehicleBasic& v) {
		v.read(in);
		return in;
	}

}

	
