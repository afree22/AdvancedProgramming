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

struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node();
    Node(int, Node*, Node*);
//    void setNext(Node*ptr){next=ptr;}
//    void setPrev(Node*pt){prev=pt;}
};



class MTFList
{
private:
    Node *head;
    Node *tail;
public:
    MTFList(){head=tail=NULL;}
    void addToTail(int);
    void search(int);
//    void MoveToFront(Node*); unnecessary
    void display();
};

#endif /* MTFLIST_H*/
