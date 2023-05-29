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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Parking.h"
#include "Motorcycle.h"
#include "Vehicle.h"
#include "Car.h"
#include "Menu.h"
#include "Utils.h"


using namespace std;
namespace sdds
{
	Parking::Parking() {
		m_fileName = nullptr;
		parkingMenu = nullptr;
		selectMenu = nullptr;
	};
	
	Parking::Parking( const char* fileName, int noOfSpots){
		if(noOfSpots < 10 || noOfSpots > MAX_NUM_SPOTS){
			setEmpty();
		}else{
			m_noOfSpots = noOfSpots;
			m_noOfParkedVehicles = 0;
		}
		for(int i = 0; i < MAX_NUM_SPOTS; i++){
			m_parkingSpots[i] = nullptr;
		}
		if (fileName == nullptr || strcmp(fileName, "") == 0) {
			setEmpty();
		}
		else {
			m_fileName = new char [strlen(fileName) + 1];
			strcpy(m_fileName, fileName);
			if (loadDataFile()) {
				// parking Menu:
				parkingMenu = new Menu("Parking Menu, select an action:");
				parkingMenu->add("Park Vehicle");
				parkingMenu->add("Return Vehicle");
				parkingMenu->add("List Parked Vehicles");
				parkingMenu->add("Find Vehicle");
				parkingMenu->add("Close Parking (End of day)");
				parkingMenu->add("Exit Program");
				// select vehicle Menu:
				selectMenu = new Menu("Select type of the vehicle:", 1);
				selectMenu->add("Car");
				selectMenu->add("Motorcycle");
				selectMenu->add("Cancel");
			}
			else {
				cout << "Error in data file" << endl;
				setEmpty();
			}
		}
	}

	Parking::~Parking() {
		saveDataFile();
		if (m_fileName != nullptr) {
			delete[] m_fileName;
			m_fileName = nullptr;
			delete parkingMenu;
			parkingMenu = nullptr;
			delete selectMenu;
			selectMenu = nullptr;
			for(int i = 0; i < m_noOfSpots; i++){
				delete m_parkingSpots[i]; //access to Vehicle pointer at index i of m_parkingSpots and delete
				m_parkingSpots[i] = nullptr;// dynamically allocated memory on heap linked by this Vehicle pointer			
			}
		}		
	};
	
	int Parking::run() {
		bool flag = false;
			if (!isEmpty()) {				
				while (!flag) {
					parkingStatus();
					int choice = parkingMenu->run();
					switch (choice) {
					case 1:
						parkVehice();
						break;
					case 2:
						returnVehice();
						break;
					case 3:
						listParkedVehice();
						break;
					case 4:
						findVehice();
						break;
					case 5:
						if (closeParking()) {
							flag = true;
						}
						break;
					case 6:
						if (exitParking()) {
							flag = true;
						}
						break;
					}
				}
			}
			if (!isEmpty()) {
				return 1;
			}
			else{
			}
		return 0;
	};

	bool Parking::isEmpty() {
		return m_fileName == nullptr;
	};
		
	void Parking::setEmpty(){
		m_fileName = nullptr;
		parkingMenu = nullptr;
		selectMenu = nullptr;
		m_noOfSpots = 0;
		m_noOfParkedVehicles = 0;
	}

	void Parking::parkingStatus() {
		cout << "****** Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << m_noOfSpots - m_noOfParkedVehicles;
		cout << " *****" << endl;
	};

	void Parking::parkVehice() {
		if(m_noOfParkedVehicles == m_noOfSpots){
			cout << "Parking is full";
		}
		else {
			bool found = false;
			int choice = selectMenu->run();
			Vehicle* v = nullptr;			
			switch (choice) {
			case 1:
				v = new Car();
				v->setCsv(false);
				v->read();
				cout << endl;
				for (int i = 0; i < m_noOfSpots; i++) {
					if (m_parkingSpots[i] == nullptr) {
						found = true;
						m_parkingSpots[i] = v; //parking
						m_parkingSpots[i]->setParkingSpot(i + 1);
						m_noOfParkedVehicles++;
						cout << "Parking Ticket" << endl;
						m_parkingSpots[i]->write();
						cout << endl;
						break;
					}
				}
				if (!found) {
					delete v;
					v = nullptr;
				}
				else {
					found = false;
				}
				break;
			case 2:
				v = new Motorcycle();
				v->setCsv(false);
				v->read();
				cout << endl;
				found = false;
				for (int i = 0; i < m_noOfSpots; i++) {
					if (m_parkingSpots[i] == nullptr) {
						found = true;
						m_parkingSpots[i] = v;
						m_parkingSpots[i]->setParkingSpot(i + 1);
						m_noOfParkedVehicles++;
						cout << "Parking Ticket" << endl;
						m_parkingSpots[i]->write();
						cout << endl;
						break;
					}
				}
				if (found) {
					found = false;
				}
				else {
					delete v;
					v = nullptr;
				}
				break;
			case 3:
				cout << "Parking Cancelled" << endl;
				return;
				break;
			}
		}	
		pause();
		cout << endl;
	};

	void Parking::returnVehice() {
		cout << "Return Vehicle" << endl;
		cout << "Enter License Plate Number: ";
		char licence[10];
		while(1){
			cin.getline(licence, 10, '\n');
			int n = strlen(licence);
			if(n < 1 || n > 8){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid License Plate, try again: ";
			}else{
				break;
			}
		}
		cout << endl;
		bool found = false;
		for(int j = 0; licence[j] != '\0'; j++){
			licence[j] = toupper(licence[j]);
		}

		int i = 0;
		for(; i < m_noOfSpots; i++){
			if(m_parkingSpots[i] != nullptr){
				if(*m_parkingSpots[i] == licence){
					found = true;
					break;
				}
			}
		}
		if(found){
			cout << "Returning:" << endl;
			m_parkingSpots[i]->setCsv(false);
			m_parkingSpots[i]->write();
			delete m_parkingSpots[i];
			m_parkingSpots[i] = nullptr;
			m_noOfParkedVehicles--;
		}else{
			cout << "License plate " << licence << " Not found" << endl;
		}
		cout << endl;
		pause();
	};

	void Parking::listParkedVehice() {
		cout << "*** List of parked vehicles ***" << endl;
		for(int i = 0; i < m_noOfSpots; i++){
			if(m_parkingSpots[i] != nullptr){
				m_parkingSpots[i]->setCsv(false);
				m_parkingSpots[i]->write();
				cout << "-------------------------------" << endl;
			}
		}
		pause();
	};

	void Parking::findVehice() {
		cout << "Vehicle Search" << endl;
		cout << "Enter License Plate Number: ";
		char licence[10];
		while(1){
			cin.getline(licence, 10, '\n');
			int n = strlen(licence);
			if(n < 1 || n > 8){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid License Plate, try again: ";
			}else{
				break;
			}
		}
		cout << endl;
		bool found = false;
		for(int j = 0; licence[j] != '\0'; j++){
			licence[j] = toupper(licence[j]);
		}	

		int i = 0;
		for(; i < m_noOfSpots; i++){
			if(m_parkingSpots[i] != nullptr){
				if(*m_parkingSpots[i] == licence){
					found = true;
					break;
				}
			}
		}
		if(found){
			cout << "Vehicle found:" << endl;
			m_parkingSpots[i]->setCsv(false);
			m_parkingSpots[i]->write();
		}else{
			cout << "License plate " << licence << " Not found" << endl;
		}
		cout << endl;
		pause();
	};

	bool Parking::closeParking() {
		if(isEmpty()){
			cout << "Closing Parking" << endl;
			return true;
		}
		char answer;
		bool flag = false;
		cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		while (true) {
			cin >> answer;
			cin.ignore(1000, '\n');
			if (answer == 'Y' || answer == 'y') {
				cout << "Closing Parking" << endl;
				for(int i = 0; i < m_noOfSpots; i++){
					if(m_parkingSpots[i] != nullptr){
						cout << endl << "Towing request" << endl;
						cout << "*********************" << endl;
						m_parkingSpots[i]->setCsv(false);
						m_parkingSpots[i]->write();
						delete m_parkingSpots[i];
						m_parkingSpots[i] = nullptr;
					}
				}
				flag = true;
				break;
			}
			else {
				if (answer != 'N' && answer != 'n') {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
				else {
					flag = false;
					break;
				}
			}
		}
		return flag;
	};

	bool Parking::exitParking() {
		string input;
		char answer;
		bool flag = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		answer = validAnswer(input);
		cin.ignore(1000, '\n');
		if (answer == 'Y' || answer == 'y') {
			cout << "Exiting program!" << endl;
			flag = true;
		}
		else {
			flag = false;
		};
		return flag;
	};

	bool Parking::loadDataFile() {
		bool flag;
		if (!isEmpty()) {
			ifstream infile; //input file stream and read its contents
			infile.open(m_fileName); //open the file stream
			Vehicle* v = nullptr;
			if (!infile.is_open())
			{
				flag = true;
			}else{
				char c;
				while (!infile.eof() && m_noOfParkedVehicles <= m_noOfSpots) //if haven't read to the end of the file
				{
					infile >> c;
					infile.ignore();
					if(infile.fail()){
						flag = true;
						break;
					}
					if(c == 'M' || c == 'm'){
						v = new Motorcycle();
						v->setCsv(true); //set to mode CSV
						v->read(infile);
					}else{
						if(c == 'C' || c == 'c'){
							v = new Car();
							v->setCsv(true);
							v->read(infile);
						}else{
							flag = false;
						}
					}

					if(infile.fail()){
						flag = false;
						delete v;
						v = nullptr;
						break;
					}else{
						m_parkingSpots[v->getParkingSpot()-1] = v;
						m_noOfParkedVehicles++;
					}
				}
			}
			infile.close();
		}else{
			flag = true;
		}
		return flag;
	};
	
	void Parking::saveDataFile() {
		if (!isEmpty()) {
			ofstream outfile; 
			outfile.open(m_fileName); 
			if (outfile.is_open())
			{
				for (int i = 0; i < m_noOfSpots; i++)
				{
					if(m_parkingSpots[i] != nullptr){
						m_parkingSpots[i]->setCsv(true);
						m_parkingSpots[i]->write(outfile);
					}
				}
			}
			outfile.close();
		}
	};

}


