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

#include<iostream>
#include<cstring>
#include <iomanip>
#include"Basket.h"

using namespace std;
namespace sdds{
    Basket::Basket(){
        b_fruits = nullptr;
        b_size = 0;
        m_price = 0;
    }

    Basket::Basket(Fruit* fruit, int size, double price){
        if(size > 0 && fruit){
            b_fruits = new Fruit[size];
            for(int i = 0; i < size; i++){
                b_fruits[i] = fruit[i];
            }
            b_size = size;
            m_price = price;
        }
        else{
            b_fruits = nullptr;
            b_size = 0;
            m_price = 0;
        }
    }

    Basket::~Basket(){
        delete[] b_fruits;
        setEmpty();
    }

    Basket::Basket(const Basket& src){
        if(src.b_fruits){
            b_fruits = new Fruit[src.b_size];
            for(int i = 0; i < src.b_size; i++){
                b_fruits[i] = src.b_fruits[i];
            }
            b_size = src.b_size;
            m_price = src.m_price;
        }
        else{
            setEmpty();
        }
    }

    void Basket::setEmpty(){
        b_fruits = nullptr;
        b_size = 0;
        m_price = 0;
    }

    Basket& Basket::operator=(const Basket& src){
        if(this != &src){
            delete[] b_fruits;
            if(src.b_fruits){
                b_fruits = new Fruit[src.b_size];
                for(int i = 0; i < src.b_size; i++){
                    b_fruits[i] = src.b_fruits[i];
                }
                b_size = src.b_size;
                m_price = src.m_price;
            }
            else{
                setEmpty();
            }
        }
        return *this;
    }

    void Basket::setPrice(double price){
        if(price >= 0){
            m_price = price;
        }
    }

    Basket::operator bool() const{
        return b_fruits != nullptr && b_size > 0;
    }

    Basket& Basket::operator+=(const Fruit& other){
        Fruit* temp = new Fruit[b_size + 1];
        for(int i = 0; i < b_size; i++){
            temp[i] = b_fruits[i];
        }
        temp[b_size] = other;
        delete[] b_fruits;
        b_fruits = temp;
        b_size++;
        return *this;
    }

}