using namespace std;

#include "IntList.h"

#include <iostream>

IntList::IntList() : head(nullptr), tail(nullptr) {}

IntList::~IntList() 
{

    clear();

}

void IntList::clear()
{
    
    IntNode* temp = nullptr;
    while(head != nullptr)
    {

        temp = head -> next;
        delete head;
        head = temp; 

    }

    tail = nullptr;

}

void IntList::push_front(int value)
{
    
    if(empty())
    {

        head = new IntNode(value);
        tail = head;

    }
    else
    {

        IntNode* newPtr = new IntNode(value);
        newPtr -> next = head; 
        head = newPtr; 

    }

}

void IntList::pop_front()
{

    if(!empty())
    {
        if(head == tail)
        {

            delete head;
            head = nullptr;
            tail = nullptr;

        }
        else
        {
            
            IntNode* temp = head;
            head = head->next;
            delete temp;

        }

    }

    if(head == nullptr)
    {

        tail = nullptr;

    }

}

bool IntList::empty() const
{

    if(head == nullptr)
        return true;
    return false;

}

const int& IntList::front() const
{

    return head -> value;

}

const int& IntList::back() const
{


    return tail -> value;


}

ostream & operator<<(ostream &out, const IntList &rhs)
{


    IntNode *temp = rhs.head;

    if(rhs.head != rhs.tail)
    {
        while(temp->next != nullptr)
        {
        
            out << temp->value << " ";

            temp = temp->next;
        

        }  
    }

    if(temp != nullptr)
    {
        out << temp->value;
    }

    return out;
}

// Start of ProAs


IntList::IntList(const IntList &og)
{

    head = nullptr;
    tail = nullptr;

    IntNode *temp = og.head;

    while(temp != nullptr)
    {

        push_back(temp->value);
        temp = temp->next;

    }

}

IntList& IntList::operator=(const IntList &rhs)
{

    if(this == &rhs)
    {
        return *this;
    }

    clear();
    if(rhs.head == nullptr)
    {

        head = nullptr;
        tail = nullptr;
        return *this;

    }

    IntNode *temp = rhs.head;

    while(temp != nullptr)
    {

        push_back(temp->value);
        temp = temp->next;

    }

    return *this;
    
}

void IntList::push_back(int value)
{

    if(empty())
    {

        head = new IntNode(value);
        tail = head;

    }
    else
    {

        IntNode *temp = new IntNode(value);
        tail->next = temp;
        tail = temp;

    }

}

void IntList::selection_sort()
{
    if(head == tail)
    {
        return;
    }

    IntNode *tempi = head;

    while(tempi->next != nullptr)
    {

        IntNode *smPtr = tempi;
        IntNode *tempj = tempi->next;

        while(tempj != nullptr)
        {

            if(smPtr->value > tempj->value)
            {

                smPtr = tempj;

            }

            tempj = tempj->next;

        }

        if(smPtr != tempi)
        {

            int temp = tempi->value;
            tempi->value = smPtr->value;
            smPtr->value = temp;

        }

        tempi = tempi->next;
        tempj = tempi;

    }

}

void IntList::insert_ordered(int value)
{

    if(head == nullptr || value <= head->value)
    {

        push_front(value);

    }
    else if(value > tail->value)
    {

        push_back(value);

    }
    else
    {

        IntNode *prev = head; 
        IntNode *curr = head->next; 

        while(curr->next != nullptr && curr->value < value)
        {

            prev = curr;
            curr = curr -> next;

        }

        IntNode *newPtr = new IntNode(value); 
        prev->next = newPtr;
        newPtr->next = curr;

    }

}

void IntList::remove_duplicates()
{

    if(head == tail || head == nullptr)
    {
        return;
    }

    IntNode *prev = nullptr;
    IntNode *curr = nullptr;

    IntNode *tempi = head;

    while(tempi != nullptr)
    {

        prev = tempi;
        curr = prev->next;

        while(curr != nullptr)
        {

            if(tempi->value == curr->value)
            {

               prev->next = curr->next;
               delete curr;
               
               if(tail == curr)
               {

                    tail = prev;

               }

               curr = prev->next;

            }
            else
            {
                prev = curr;
                curr = curr->next;
            }

        }

        tempi = tempi -> next;

    }

}


// End of ProAs