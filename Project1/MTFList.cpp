//
//  MTFList.cpp
//  Project1
//
//  Created by Anne Freeman on 9/25/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//

#include "MTFList.h"
#include <iostream>

//constructor with parameters for Node
DLLNode::DLLNode(int d, DLLNode *n = NULL, DLLNode *p = NULL)
{
    data = d;
    next = n;
    prev = p;
}

void MTFList::addToTail(int value)
{
    //if list isn't empty
    if(tail != NULL)
    {
        tail = new DLLNode(value, NULL, tail);
        tail->prev->next = tail;
    }
    
    //list is empty
    else
    {
        head = tail = new DLLNode(value);
    }
}


bool MTFList::search(int value)
{
    DLLNode *temp = head;
    bool found = false;
    
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            found = true;
            if (temp->prev == NULL)
            {
                //at beginning so do not need to move it
            }
            else if(temp->next == NULL)
            {
                // moving the last DLLNode to the front
                
                tail = temp->prev;
                temp->prev->next = NULL;
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
            else
            {
                // Move item from middle to front
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
            temp = NULL; // set pointer to DLLNode to NULL to exit loop
        }
        
        else
        {
            // only increment pointer if not found
            temp = temp->next;
        }
    }
    return found;
}

        

void MTFList::display()
{
    DLLNode *temp=new DLLNode;
    temp=head;
    while(temp!=NULL)
    {
        std::cout<< temp->data <<"\t";
        temp=temp->next;
    }
}





MTFList::~MTFList()
{
    if(head == NULL)
    {
        //nothing b/c list is empty
    }
    
    if(head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
}



