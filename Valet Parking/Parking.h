/*
*****************************************************************************
						  Milestone - #5
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Dec 09, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"
#include "Vehicle.h"
#define MAX_NUM_SPOTS 100
namespace sdds
{
	class Parking
	{
		int m_noOfSpots = 0;
		Vehicle* m_parkingSpots[MAX_NUM_SPOTS]; //static array of pointers to Vehicle objects
		int m_noOfParkedVehicles = 0;
		char* m_fileName = nullptr;
		Menu* parkingMenu = nullptr;
		Menu* selectMenu = nullptr;

		bool isEmpty() ;
		void setEmpty();
		void parkingStatus() ;
		void parkVehice();
		void returnVehice();
		void listParkedVehice();
		void findVehice();
		bool closeParking();
		bool exitParking();
		bool loadDataFile();
		void saveDataFile();
		

	public:
		Parking();
		Parking(const char* fileName);
		Parking( const char* fileName, int noOfSpots);
		~Parking ();
		Parking(const Parking& p) = delete;
		Parking& operator=(const Parking& p) = delete;
		int run();
	};
}

#endif