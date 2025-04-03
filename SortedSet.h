#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <ostream>

#include "IntList.h"

using namespace std;

class SortedSet : public IntList  
{

private:


public:

    SortedSet();
    ~SortedSet();
    SortedSet(const SortedSet&); // Copy Constructor
    SortedSet(const IntList&); // Copy Constructor


    SortedSet operator|(const SortedSet& rhs);
    SortedSet operator&(const SortedSet& rhs);
    SortedSet operator|=(SortedSet& rhs);
    SortedSet operator&=(SortedSet& rhs);
    
    

    bool in(int value); // If part of the set then return true;

    void add(int value); // Add to list as long as list doesn't have that value in the set already
    void push_front(int value); // Just call add to it
    void push_back(int value); // No Duplicates, Advice is to look at add
    void insert_ordered(int value); // No Duplicates, Advice is to look at add

};

#endif