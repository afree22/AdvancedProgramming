//
//  main.cpp
//  recursiveSequentialSearch
//
//  Created by Anne Freeman on 9/13/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//

#include <iostream>
using namespace std;

void createNode(int value);

struct Node
{
    int data;
    Node* next;
};

class list
{
private:
    Node *head;
    Node *tail;
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    Node *getHead(){return head;}
    void createNode(int);
    void display();
    int deleteFromTail();
    int search(int i, Node *ptr, int c);
};

int list::deleteFromTail()
{
    if(head == NULL) //list of size 0
    {
        cout << "an error has occured - empty list" << endl;
    }
    int info = tail->data;
    if(head==tail) //list of size 1
    {
        delete head;
        head = tail = 0;
    }
    else //2 or more nodes on the list
    {
        Node *tmp;
        //loop to find the node before tail
        for(tmp=head; tmp->next != tail; tmp = tmp->next)
        {
            
        }
        delete tail;
        tail = tmp;
        tail->next=0;
    }
    return info;
}

void list::createNode(int value)
{
    Node *temp=new Node;
    temp->data=value;
    temp->next=NULL;
    if(head == NULL)
    {
        head=temp;
        tail=temp;
        temp=NULL;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void list::display()
{
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}

int list::search(int i, Node *ptr, int counter)
{
    
    if(ptr == NULL)
    {
        return -1;
        // The node is not on the list or
        // the list doesn't exist
    }
    
    if (i == ptr->data)
    {
        return counter;
    }
    else
    {
        counter = counter + 1;
        return search(i, ptr=ptr->next, counter);
    }
    
}



int main(int argc, const char * argv[]) {
   
    
    list myList;
    for(int i = 1000; i > 0; i--)
    {
        myList.createNode(i);
        i = i/2;
    }
    myList.display();
    cout << endl;


    cout << "results of search: " << endl;
    cout << myList.search(1, myList.getHead(), 0) << endl;
    
    return 0;
}











