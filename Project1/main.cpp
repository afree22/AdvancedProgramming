//
//  main.cpp
//  Project1
//
//  Created by Anne Freeman on 9/25/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//


#include "MTFList.h"
#include "orderedList.h"
#include <iostream>
#include <time.h>
using namespace std;


int main(int argc, const char * argv[])
{
    

//    
//    MTFList myList;
//    
//    clock_t start1 = clock();
//    for(int i = 0; i < 1000; i=i*2)
//    {
//        myList.addToTail(i);
//        i++;
//    }
//    clock_t end1 = clock();
//    double time1 = (double) (end1-start1) / CLOCKS_PER_SEC * 1000.0;
//    
//    cout << "time to add items to MTFList: "<< time1 << endl;
//    
//    myList.display();
//    cout << endl << endl;
//    
//    
//    clock_t start2 = clock();
//    myList.search(30);
//    clock_t end2 = clock();
//    double time2 = (double) (end2-start2) / CLOCKS_PER_SEC * 1000.0;
//    cout << "time to search for item in MTFList: " << time2 << endl;
//    
//    myList.display();
//    cout << endl << endl;
    
    
    
    
    
    
    
    OrderedList myOrderedList;
    for(int i = 0; i < 20; i++)
    {
        myOrderedList.createNode(i);
    }
    myOrderedList.setLength(20);
    cout << "list before sorting" << endl;
    myOrderedList.display();
    cout << endl << endl;

    Node *ptr =  myOrderedList.mergeSort(myOrderedList.getHead());
    cout << "list after sorting" << endl;
    myOrderedList.displayMergedList(ptr);
    cout << endl << endl;
    
    

    
    
    
    return 0;
}
