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
    HtmlText::HtmlText(){
        m_title = nullptr;
    }

    HtmlText::HtmlText(const char* title){
        m_title = nullptr;
        if(title != nullptr){
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    HtmlText::HtmlText(const HtmlText& src){
        m_title = new char[strlen(src.m_title) + 1];
        strcpy(m_title, src.m_title);
        //Text::operator=(src);
        this->setContent(src);
    }

    HtmlText& HtmlText::operator=(const HtmlText& src){
        if(this != &src){
            delete[] m_title;
            m_title = nullptr;
            if(src.m_title != nullptr){
                m_title = new char[strlen(src.m_title) + 1];
                strcpy(m_title, src.m_title);
            }
            //Text::operator=(src); //??????????
            this->setContent(src);
        }
        return *this;
    }

    HtmlText::~HtmlText(){
        delete[] m_title;
        m_title = nullptr;
    }

    std::ostream& HtmlText::write(std::ostream& os) const{
        bool ms = false;
        os << "<html><head><title>";
        if(m_title != nullptr){
            os << m_title;
        }else{
            os << "No Title";
        }

        os << "</title></head>\n<body>\n";

        if(m_title != nullptr){
            os << "<h1>" << m_title << "</h1>\n";
        }

        //use overloaded operator[] to print the content
        int i = 0;
        while(true){
            switch((*this)[i]){
                case ' ':
                    if(ms){
                        os << "&nbsp;"; 
                    }else{
                        ms = true;
                        os << " ";
                    }
                    break;
                case '<':
                    os << "&lt;";
                    ms = false;
                    break;
                case '>':
                    os << "&gt;";
                    ms = false;
                    break;
                case '\n':
                    os << "<br />\n";
                    ms = false;
                    break;
                case '\0':
                    os << "</body>\n</html>";
                    return os; //return the ostream object
                default: 
                    os << (*this)[i];
                    ms = false;
                    break;
            }
            i++;
        }
        return os;
    }

    std::ostream& operator <<(std::ostream &os,const HtmlText& src){
        return src.write(os);
    }
        
}