using namespace std;
#include <iostream>

#include "SortedSet.h"

// I'M VERY HAPPY RN

SortedSet::SortedSet(): IntList(){}

SortedSet::~SortedSet(){}

SortedSet::SortedSet(const SortedSet &rhs)
{

    IntList::operator=(rhs);

} 

SortedSet::SortedSet(const IntList &rhs)
{

    IntList temp = rhs;
    temp.IntList::remove_duplicates();
    temp.IntList::selection_sort();
    IntList::operator=(temp);

}

bool SortedSet::in(int value)
{

    IntNode *temp = head;

    bool ans = false;

    while(temp != nullptr && ans == false)
    {

        if(value == temp->value)
        {

            ans = true;

        }

        temp = temp->next;

    }

    return ans;

}

SortedSet SortedSet::operator|(const SortedSet& rhs) // Combine fully
{

    IntNode *temp = head;

    SortedSet tempList = rhs; 

    while(temp != nullptr)
    { 

        tempList.insert_ordered(temp->value);
        temp = temp->next;

    }

    return tempList;

}

SortedSet SortedSet::operator&(const SortedSet& rhs) // Keeps non-duplicates
{
    IntNode *temp = head;

    SortedSet tempList; 
    
    SortedSet dumbConstRule = rhs; 

    while(temp != nullptr)
    { 
        
        if(dumbConstRule.in(temp->value))
        {
            tempList.insert_ordered(temp->value);
        }

        temp = temp->next;

    }

    return tempList;

}

SortedSet SortedSet::operator|=(SortedSet& rhs)
{

    *this = *this | rhs;
    return *this;

}

SortedSet SortedSet::operator&=(SortedSet& rhs)
{

    *this = *this & rhs;
    return *this;

}

void SortedSet::push_front(int value)
{

    if(!in(value))
    {
        add(value);
    }

}

void SortedSet::push_back(int value)
{

    if(!in(value))
    {
        add(value);
    }

}

void SortedSet::insert_ordered(int value)
{

    if(!in(value))
    {

        add(value);

    }

}

void SortedSet::add(int value)
{

    if(!in(value))
    {

        IntList::insert_ordered(value);

    }

}


