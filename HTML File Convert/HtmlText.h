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

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include "Text.h"
#include<iostream>

namespace sdds{
    class HtmlText : public Text{
        private:
            char* m_title;
        public:
            HtmlText();
            HtmlText(const char* title);
            HtmlText(const HtmlText& src);
            HtmlText& operator=(const HtmlText& src);
            ~HtmlText();
            std::ostream& write(std::ostream& os = std::cout) const;
            friend std::ostream& operator <<(std::ostream &os, const HtmlText& src);
    };
}

#endif