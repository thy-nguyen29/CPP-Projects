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

#ifndef SDDS_Shape_H
#define SDDS_Shape_H
namespace sdds{
    class Shape{
        public:
            virtual void draw(std::ostream& os) const = 0;
            virtual void getSpecs(std::istream& is) = 0;
            virtual ~Shape();
            friend std::ostream& operator<<(std::ostream& os, const Shape& s);
            friend std::istream& operator>>(std::istream& is, Shape& s);
    };
}
#endif