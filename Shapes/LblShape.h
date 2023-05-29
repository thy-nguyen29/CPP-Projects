/*
*****************************************************************************
                          Workshop - #8
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 15, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_LblShape_H
#define SDDS_LblShape_H
#include "Shape.h"
namespace sdds{
    class LblShape : public Shape{
    private:
        char* m_label;
    protected:
        const char* label()const;
    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape& LblShape) = delete;
        LblShape& operator=(const LblShape& LblShape) = delete;
        void getSpecs(std::istream& is); 
    };
}
#endif