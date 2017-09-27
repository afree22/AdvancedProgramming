//
//  MTFList.cpp
//  Project1
//
//  Created by Anne Freeman on 9/25/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//

#include "MTFList.h"
#include <iostream>
using namespace std;

Node::Node()
{
    next = NULL;
    prev = NULL;
}
Node::Node(int d, Node *n = NULL, Node *p = NULL)
{
    data = d;
    next = n;
    prev = p;
}

void MTFList::addToTail(int value)
{
    if(tail != 0)
    {
        tail = new Node(value, 0, tail);
        tail->prev->next = tail;
    }
    else
    {
        head = tail = new Node(value);
    }
}


void MTFList::search(int value)
{
    Node *temp = head;
    bool change = false;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            if (temp->prev == NULL)
            {
                //at beginning so nothing special
            }
            else if(temp->next == NULL)
            {
                /* Remove from end */
                // temp is last node
                
                tail = temp->prev;
                temp->prev->next = NULL;
                change = true;
            }
            else
            { /* Remove from middle */
  
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                change = true;
            }
            
            if(change)
            {
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
            temp = NULL;
        }
        else
        {
            temp = temp->next;
        }
    }
}

        

void MTFList::display()
{
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
        cout<< temp->data <<"\t";
        temp=temp->next;
    }
    cout << endl;
}



