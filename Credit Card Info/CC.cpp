/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Sep 29, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include<iostream>
#include<string>
#include "CC.h"
#include "Utils.h"
using namespace std;
namespace sdds{
    // class CC
    // {       
    //     private:
            bool CC::validate(const char *name, unsigned long long cardNo, short cvv, short expMon, short expYear) const{
                if (name == nullptr || name[0] == '\0') {
                    return false;
                }
                int i = 0;
                while (name[i]){ 
                    i++;
                }
                if (i <= 2 || cardNo < 4000000000000000 || cardNo > 4099999999999999 || cvv < 100 || cvv > 999 || expMon < 1 || expMon > 12 || expYear < 22 || expYear > 32) {
                    return false;
                }

                return true;
            };

            void CC::prnNumber() const{
                unsigned long long temp = cardNo;
                int fourth = temp % 10000;
                temp = temp / 10000;

                int third = temp % 10000;
                temp = temp / 10000;

                int second = temp % 10000;
                temp = temp / 10000;

                int first = temp % 10000;
                temp = temp / 10000;

                cout.width(4);
                cout.fill('0');
                cout.setf(ios::left);
                cout << first << " ";

                cout.width(4);
                cout.fill('0');
                cout.setf(ios::right);
                cout << second << " ";

                cout.width(4);
                cout.fill('0');
                cout.setf(ios::right);
                cout << third << " ";

                cout.width(4);
                cout.fill('0');
                cout.setf(ios::right);
                cout << fourth;
            };

        // public:
            void CC::set(){
                name = nullptr;
                cardNo = 0;
                cvv = 0;
                expMon = 0;
                expYear = 0;
            };

            void CC::cleanUp(){
                delete[] name;
                set();
            };

            bool CC::isEmpty() const{
                return name == nullptr;// && cardNo == 0 && cvv == 0 && expMon == 0 && expYear == 0;
            };

            void CC::set(const char *cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear){
                cleanUp();
                if(validate(cc_name, cc_no, cvv, expMon, expYear)){
                    name = new char[sdds::strlen(cc_name) + 1];
                    sdds::strcpy(name, cc_name, sdds::strlen(cc_name) + 1);
                    cardNo = cc_no;
                    this->cvv = cvv;
                    this->expMon = expMon;
                    this->expYear = expYear;
                }
            };

            bool CC::read() {
                cleanUp();
                int isFail = 0;
                char cc_name[71];
                unsigned long long cc_no;
                short cvv, expMon, expYear;
              
                cout << "Card holder name: ";
                cin.getline(cc_name, 71, '\n');
                if (!cin.fail()) {
                    cout << "Credit card number: ";
                    cin >> cc_no;
                    cin.ignore();
                    if (!cin.fail()) {
                        cout << "Card Verification Value (CVV): ";
                        cin >> cvv;
                        cin.ignore();
                        if (!cin.fail()) {
                            cout << "Expiry month and year (MM/YY): ";
                            cin >> expMon;
                            cin.ignore();
                            if (cin.fail()) {
                                isFail = 1;
                                cin.clear();
                            }
                            cin >> expYear;
                            cin.ignore();
                            if (cin.fail()) {
                                isFail = 1;
                                cin.clear();
                            }
                        }
                        else {
                            isFail = 1;
                            cin.clear();
                        }
                    }
                    else {
                        isFail = 1;
                        cin.clear();
                    }
                }
                else {
                    isFail = 1;
                    cin.clear();
                }

                if (isFail) {
                    cin.clear();
                    while ((getchar()) != '\n');
                }

                else
                {
                    set(cc_name, cc_no, cvv, expMon, expYear);
                }
                return !isEmpty();
            };

            void CC::display(int row) const {
                if (!isEmpty()) {
                    if (row > 0) {
                        cout << "| ";
                        cout.width(3);
                        cout.fill(' ');
                        cout.setf(ios::right);
                        cout << row << " ";

                        if (sdds::strlen(name) <= 30) {
                            cout << "| ";
                            int i = 0;
                            int n = strlen(name);
                            while (i <= 30) {
                                if (i < n)
                                    cout << name[i];
                                else
                                    cout << " ";
                                i++;
                            }
                        }
                        else {
                            cout << "| ";
                            int i = 0;
                            while (i < 30) {
                                cout << name[i];
                                i++;
                            }
                            cout << " ";
                        }

                        cout << "| ";
                        prnNumber();
                        cout << " ";

                        cout << "| ";
                        cout << cvv << " ";

                        cout << "| ";
                        cout.width(2);
                        cout.fill(' ');
                        cout.setf(ios::right);
                        cout << expMon;
                        cout << "/" << expYear << " |" << endl;
                    }
                    else {
                        cout << "Name: " << name << endl;
                        cout << "Creditcard No: ";
                        prnNumber();
                        cout << endl;
                        cout << "Card Verification Value: " << cvv << endl;
                        cout << "Expiry Date: " << expMon << "/" << expYear << endl;
                    }
                }
                else {
                    cout << "Invalid Credit Card Record" << endl;
                }
            };
    
}