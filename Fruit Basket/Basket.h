/*
*****************************************************************************
                          Workshop - #6 (P2)
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Oct 30, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket{
        private:
            Fruit* b_fruits;
            int b_size;
            double m_price;
        
        public:
            Basket();
            Basket(Fruit* fruit, int size, double price);
            ~Basket();
            Basket(const Basket& src);
            void setEmpty();
            Basket& operator=(const Basket& src);
            void setPrice(double price);
            operator bool() const;
            Basket& operator+=(const Fruit& other);
            
            friend std::ostream &operator<<(std::ostream &os, Basket &basket)
            {
                if (basket.b_fruits && basket.b_size > 0)
                {
                    os << "Basket Content:" << endl;
                    for (int i = 0; i < basket.b_size; i++)
                    {
                        os.width(10);
                        os.fill(' ');
                        os.setf(ios::right);
                        os << basket.b_fruits[i].m_name << ": ";
                        os << fixed << setprecision(2) << basket.b_fruits[i].m_qty << "kg" << endl;
                    }
                    os << "Price: " << fixed << setprecision(2) << basket.m_price << endl;
                }
                else
                {
                    os << "The basket is empty!" << endl;
                }
                return os;
            }
    };

}
#endif 