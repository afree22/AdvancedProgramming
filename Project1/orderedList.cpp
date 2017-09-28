//
//  orderedList.cpp
//  Project1
//
//  Created by Anne Freeman on 9/27/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//

#include "orderedList.h"
#include <iostream>


Node::Node(int d)
{
    data = d;
    next = NULL;
}


void OrderedList:: createNode(int value)
{
    //set values for new node
    Node *addMe=new Node;
    addMe->data=value;
    addMe->next=NULL;
    
    //add node to end of list
    if(head == NULL)
    {
        head=addMe;
        addMe=NULL;
    }
    else
    {
        addMe->next = head;
        head = addMe;
    }
}

Node* OrderedList::Split(Node* list)
{
    Node* middle = NULL;
    Node* right = NULL;
    int i;
    
    if(list->next!= NULL) //If list is longer then one node continue...
    {
        middle = list;
        for(i=1; i<(length)/2; i++)
        {
            middle = middle->next; //navigate to the center of the list
        }
        right = middle->next; //Create the right sublist
        middle->next = NULL; //Split it from the left sublist
        return right; //return head of right
    }
    else
        return NULL;
}

    

Node* OrderedList::Merge(Node* firstNode, Node* secondNode)
{
    Node* toReturn = NULL;
    Node* tmp = NULL;
    Node* newl = NULL;
    
    if(firstNode == nullptr)
        return secondNode; //firstNode is empty no merging is necessary return list 2
    else if(secondNode == nullptr)
        return firstNode; //list 2 is empty...
    else
    {
        if (firstNode->data < secondNode->data) //compare the first nodes
        {
            newl = firstNode;
            firstNode = firstNode -> next;
            tmp = newl;
        }
        else
        {
            newl = secondNode;
            secondNode = secondNode -> next;
            tmp = newl;
        }
        while(firstNode != NULL && secondNode != NULL) //special sauce is here
        {
            if(firstNode->data < secondNode->data)
            {
                tmp->next = firstNode;
                tmp = tmp->next;
                firstNode = firstNode->next;
            }
            else
            {
                tmp -> next = secondNode;
                tmp = tmp -> next;
                secondNode = secondNode -> next;
            }
        } //end while
        
        if(firstNode == nullptr)
        {
            tmp -> next = secondNode;
        }
        
        else
            tmp->next = firstNode;
        return newl;
    }

//    return toReturn;
}



Node* OrderedList::mergeSort(Node* left)
{
    Node* right; // to create a sublist with
    
    if(left->next != NULL)// if list isn't shorter then 1 entry then sort it...
    {
        right = Split(left); //create the right sublist
        return Merge(mergeSort(left), mergeSort(right)); //Merge the two sorted lists and return them as one sorted list
    }
    
    //otherwise list is 1 long or shorter so return it
    return left;
}



OrderedList::~OrderedList()
{

    Node* current = head;
    while(current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

void OrderedList::display()
{
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
        std::cout<< temp->data <<"\t";
        temp=temp->next;
    }
}

void OrderedList::displayMergedList(Node *ptr)
{
    Node *temp=new Node;
    temp=mergeSort(ptr);
    while(temp!=NULL)
    {
        std::cout<< temp->data <<"\t";
        temp=temp->next;
    }
}



