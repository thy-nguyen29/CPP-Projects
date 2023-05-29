/*
*****************************************************************************
                          Workshop - #9
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 24, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "HtmlText.h"
#include "Text.h"
using namespace std;
namespace sdds{
    Text::Text(){
        m_content = nullptr;
    }

    Text::Text(const Text& src){
        m_content = new char[strlen(src.m_content) + 1];
        strcpy(m_content, src.m_content);
    }

    Text& Text::operator=(const Text& src){
        if(this != &src){
            delete[] m_content;
            m_content = new char[strlen(src.m_content) + 1];
            strcpy(m_content, src.m_content);
        }
        return *this;
    }

    Text::~Text(){
        delete[] m_content;
        m_content = nullptr;
    }

    unsigned Text::getFileLength(std::istream& is){
        unsigned len{};
        if (is) {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // tell what is the positions (end position = size)
            len = unsigned(is.tellg());
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }

    std::istream& Text::read(std::istream& is){
        delete[] m_content;
        m_content = new char[getFileLength(is) + 1];
        char c;
        int i = 0;
        while (is.get(c)){
            m_content[i] = c;
            i++;
        }
        m_content[i] = '\0';
        if(i > 0){
            is.clear();
        }
        return is;
    }

    std::ostream& Text::write(std::ostream& os) const{
        os << m_content;
        return os;
    }

    std::istream& operator>>(std::istream &is, Text& src){
        src.read(is);
        return is;
    }

    std::ostream& operator<<(std::ostream &os, Text& src){
        src.write(os);
        return os;
    }

    const char& Text::operator[](int index)const{
        if(m_content != nullptr && (index >= 0 && index < (int)strlen(m_content))){
            return m_content[index];
        }
        else{
            return m_content[strlen(m_content)];
        }
    }
    void Text::setContent(const Text& src) {
        delete[] m_content;
        m_content = new char[strlen(src.m_content) + 1];
        strcpy(m_content, src.m_content);
    }
}