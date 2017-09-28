//
//  MTFList.h
//  Project1
//
//  Created by Anne Freeman on 9/25/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//

#ifndef MTFLIST_H
#define MTFLIST_H

#include <stdio.h>


//Nodes to be stored in MTFList
struct DLLNode
{
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(){next = prev = NULL;}
    DLLNode(int d, DLLNode *n, DLLNode *p);
};


// Linked list where items will move to front
// is a doubly linked list
class MTFList
{
private:
    // list keeps track of first and last DLLNode
    DLLNode *head;
    DLLNode *tail;
public:
    MTFList(){head=tail=NULL;}
    void addToTail(int);
    bool search(int);
    void display();
    ~MTFList();
};


#endif /* MTFLIST_H*/
