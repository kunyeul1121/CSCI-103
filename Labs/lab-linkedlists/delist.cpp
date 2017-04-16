#include <iostream>
#include "delist.h"
#include <stdlib.h>

using namespace std;

    // Constructs an empty Double-Ended List
    DEList::DEList()
    {
        head = NULL;
        tail = NULL;
    }
    // Destructor to clean-up memory of current list
    DEList::~DEList()
    {
        DEItem* temp = tail;
        while(tail != head)
        {
            tail = tail->prev;
            delete temp;
            temp = tail;
        }
        delete tail;
    }
    // returns a Boolean 'true' if the list is empty
    bool DEList::empty()
    {
        if(head == NULL && tail == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // returns number of items in the list
    int DEList::size()
    {
        int count = 0;

        DEItem* temp = head;

        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    // returns front item or -1 if empty list
    int DEList::front()
    {
        if(empty())
        {
            return -1;
        }
        else
        {
            return head->val;
        }
    }
    // returns back item or -1 if empty list
    int DEList::back()
    {
        if(empty())
        {
            return -1;
        }
        else
        {
            return tail->val;
        }
    }
    // Adds a new integer to the front of the list
    void DEList::push_front(int new_val)
    {
        DEItem* temp = new DEItem;
        temp->val = new_val;
        temp->prev = NULL;
        temp->next = head;

        if(empty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            head->prev = temp;
            head = temp;
        }
    }
    // Adds a new integer to the back of the list
    void DEList::push_back(int new_val)
    {
        DEItem* temp = new DEItem;
        temp->val = new_val;
        temp->prev = tail;
        temp->next = NULL;

        if(empty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    // Removes the front item of the list (if it exists)
    void DEList::pop_front()
    {
        DEItem* temp;
        if(!empty())
        {
            if(size() == 1)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp = head->next;
                temp->prev = NULL;
                delete head;
                head = temp;
            }
        }
    }
    // Removes the back item of the list (if it exists)
    void DEList::pop_back()
    {
        DEItem* temp;
        if(!empty())
        {
            if(size() == 1)
            {
                delete tail;
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp = tail->prev;
                delete tail;
                tail = temp;
                tail->next = NULL;
            }
        }
    }