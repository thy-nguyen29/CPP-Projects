#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
#include<iostream>
using namespace std;

namespace sdds 
{
    class NameTag
    {
        private:
            char name[51];
        public:
            void set(const char *name);
            char* getName()
            {
                return this->name;
            }
            void print();
            void print(int size);
    };
}
#endif