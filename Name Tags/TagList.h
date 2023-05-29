#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_
#include<iostream>
#include "NameTag.h"
using namespace std;

namespace sdds{
    class TagList
    {
        public:
            NameTag *NameTags;
            int numTags;
            int longestTag;
        public:
            void set();
            void set(int num);
            void add(const NameTag &nt);
            void print();
            void cleanup();
    };
}
#endif