//
//  main.cpp
//  COSC160-HW2
//
//  Created by Anne Freeman on 9/13/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//

#include <iostream>
using namespace std;

int removeOdd(int data[], int n);
int arrayAdd(int data[], int n);





// Write a member function to reverse a singly linked list
// using only one pass through the list
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
    void reverseList();
    void createNode(int);
    void display();
    int deleteFromTail();
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

void list::reverseList()
{
    if(head == NULL)
    {
        //do nothing
    }
    else
    {
        Node *prev = NULL;
        Node *current = NULL;
        Node *next = NULL;
        current = head;
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
}









struct DLLNode
{
    int info;
    DLLNode *next;
    DLLNode *prev;
    DLLNode()
    {
        next = 0;
        prev = 0;
    }
    DLLNode(int i, DLLNode *n = 0, DLLNode *p = 0)
    {
        info = i;
        next = n;
        prev = p;
    }
};

class DoublyLinkedList
{
protected:
    DLLNode *head;
    DLLNode *tail;
public:
    DoublyLinkedList()
    {
        head = 0;
        tail = 0;
    }

    void display();
    void addToDLLTail(int);
    int deleteFromDLLTail();
    
    
};

void DoublyLinkedList:: addToDLLTail(int value)
{
    if(tail != 0)
    {
        tail = new DLLNode(value, 0, tail);
        tail->prev->next = tail;
    }
    else
    {
        head = tail = new DLLNode(value);
    }
}

int DoublyLinkedList::deleteFromDLLTail()
{
    if(head == NULL)
    {
        cout << "error occured - empty list" << endl;
    }
    
    int data = tail->info;
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
    return data;
}

void DoublyLinkedList::display()
{
    DLLNode *temp=new DLLNode;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
}

int main(int argc, const char * argv[])

{
    //    int test[7] = {3, 8, 12, 13, 18, 23, 46};
    //    int easytest[5] = {5,3,2, 2, 2};
    //    int sum = arrayAdd(easytest, 5);
    //    int newSize = removeOdd(test, 7);
    //
    //    for (int i = 0; i < newSize; i++)
    //    {
    //        cout << test[i] << " ";
    //    }
    //    cout << "The sum is: " << sum << endl;
    
//    list myList;
//    for(int i = 0; i < 10; i++)
//    {
//        myList.createNode(i);
//    }
//    myList.display();
//    cout << endl;
//    
//    myList.reverseList();
//    myList.display();
    
    DoublyLinkedList dllList;
   // cout << "Testing delete function" << endl;
    //dllList.deleteFromDLLTail();
    //dllList.display();
    
    cout << "Testing list size 1" << endl;
    dllList.addToDLLTail(18);
    dllList.display();
    dllList.deleteFromDLLTail();
    dllList.display();
    cout << endl;
    
        for(int i = 0; i < 10; i++)
        {
            dllList.addToDLLTail(i);
        }
    dllList.display();
    
    cout << "Testing delete function" << endl;
    dllList.deleteFromDLLTail();
    dllList.deleteFromDLLTail();
    dllList.deleteFromDLLTail();
    dllList.display();
    
    
    
    cout << endl;
    return 0;
}

int removeOdd(int data[], int n)
{
    
    for(int i = 0; i < n; i++)
    {
        
        int currentVal = *(data+i);
        
        if(currentVal%2)
        {
            int *arrayPtr = (data+i);
            
            for(int j = i; j < n; j++)
            {
                int *temp = arrayPtr;
                temp++;
                *arrayPtr = *temp;
                arrayPtr++;
            }
            n--;
            i--;
        }
    }
    return n;
}


int arrayAdd(int data[], int n)
{
    int sum = *data;
    
    for(int i = 1; i <n; i++)
    {
        sum += *(data+i);
    }
    return sum;
}