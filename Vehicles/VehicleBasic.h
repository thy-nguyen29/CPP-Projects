/*
Name: Thy Nguyen
Email: nnguyen90@myseneca.ca
Student ID: 105310221
Date: Nov 10, 2022
Section: NFF
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include <iostream>
using namespace std;
namespace sdds
{
	const char MAX_NUM_LEN = 9;
	const char MAX_ADD_LEN = 64;

	class VehicleBasic
	{
		char v_plate[MAX_NUM_LEN + 1];
		char v_address[MAX_ADD_LEN + 1];
		int v_year{};

	public:
		VehicleBasic(const char* plate, int year );
		void NewAddress(const char* address);
		virtual std::ostream& write(std::ostream& os);
		virtual std::istream& read(std::istream& in);
	};
	std::ostream& operator << (std::ostream& os,  VehicleBasic v);
	std::istream& operator >> (std::istream& is,  VehicleBasic& v);

}

#endif

