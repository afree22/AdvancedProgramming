//
//  orderedList.hpp
//  Project1
//
//  Created by Anne Freeman on 9/27/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//

#ifndef orderedList_h
#define orderedList_h

#include <stdio.h>

struct Node
{
    int data;
    Node *next;
    Node(){next = NULL;}
    Node(int d);
};


class OrderedList
{
private:
    // list keeps track of first and last node
    Node *head;
    int length;
    
public:
    OrderedList(){head = NULL;}
    Node* getHead(){return head;}
    int getLength(){return length;}
    void setLength(int l){length=l;}
    void createNode(int); //adds Node to
    bool search(int i); //binary search b/c ordered
    Node* Split(Node*);
    Node* mergeSort(Node *);
    Node* Merge(Node*, Node*);
    void display();
    void displayMergedList(Node*);
    ~OrderedList();
    
};

#endif /* orderedList_h */
