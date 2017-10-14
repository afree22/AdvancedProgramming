//
//  main.cpp
//  Project1
//
//  Created by Anne Freeman on 9/25/17.
//  Copyright © 2017 Anne Freeman. All rights reserved.
//


#include "MTFList.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
//#include <time.h>
using namespace std;


void merge(int data[], int left, int mid, int right);
void mergeSort(int data[], int left, int right);
int searchList(int [],int left, int right, int val);
void displayList(int data[], int size);

int main(int argc, char * argv[])
{
    string inputFileName = " ";
    inputFileName = string(argv[1]);
    fstream inFile;
    inFile.open(inputFileName.c_str());
    
    
    if(!inFile)
    {
        cout << "File failed to open" << endl;
        
    }

    else
    {
        //get size of array
        int arraySize = 0;
        inFile >> arraySize;
        
        
        //Create MTFlist and orderedList
        MTFList moveFrontList;
        int orderedList[arraySize];
        int temp = 0;
        
        
        //Add elemented from inFile to MTFlist and orderedList
        for(int i = 0; i<arraySize; i++)
        {
            inFile >> temp;
            moveFrontList.addToTail(temp);
            orderedList[i] = temp;
        }
        
        // get the number of terms to search for
        int searchTerms = 0;
        inFile >> searchTerms;
        
        double sumMTFTime = 0;
        double sumOrderedListTime = 0;
        clock_t timeBegin, timeEnd;
        
        
        //mergeSort to order the list -- do it outside of loop
        timeBegin = clock();
        mergeSort(orderedList, 0, (arraySize-1));
        timeEnd = clock();
        sumOrderedListTime += ((double)(timeEnd-timeBegin))/CLOCKS_PER_SEC;
        
        
        
        // search for the terms and sum the times for each list
        for(int j = 0; j<searchTerms; j++)
        {
            inFile >> temp;
            timeBegin = clock();
            moveFrontList.search(temp);
            timeEnd = clock();
            sumMTFTime += ((double)(timeEnd-timeBegin))/CLOCKS_PER_SEC;
            
            timeBegin = clock();
            searchList(orderedList, 0, (arraySize-1), temp);
            timeEnd = clock();
            sumOrderedListTime += ((double)(timeEnd-timeBegin))/CLOCKS_PER_SEC;
        }
    
        
        //Output times for each list
        cout << "Time to complete retrievals for MTF List: "<< fixed << setprecision(6) << sumMTFTime << endl;
        cout << "Time to sort and complete retrievals for Ordered List: "<< fixed << setprecision(6) << sumOrderedListTime << endl;
    
        if(sumMTFTime < sumOrderedListTime)
        {
            cout << "Retrieving from the MTF list was faster" << endl;
        }
        else if(sumMTFTime > sumOrderedListTime)
        {
            cout << "Sorting and retrieving from Ordered List was faster" << endl;
        }
        else
        {
            cout << "It took the same time to retrieve from the MTF list ";
            cout << "as it did to sort and retrieve from the ordered list" << endl;
        }
        inFile.close();
        
    }
    
    
    
    return 0;
}







void displayList(int data[], int size)
{
    for(int i = 0; i<size; i++)
    {
        cout << data[i] << "\t";
    }
    cout << endl << endl;
}




void mergeSort(int data[], int left, int right)
{
    

    if(right < left)
    {

        int mid = (right+left)/2;
        
        // Sort first and second halves
        mergeSort(data, left, mid);     //left half of data
        mergeSort(data, mid+1, right);  //right half of data
        
        merge(data, left, mid, right);
    }
}





// Merges two subarrays of data[] by creating a new array
void merge(int data[], int left, int mid, int right)
{
    int arraySize = (right-left)+1;
    int *sortedArray = new int[arraySize]();
    
    int start = left;
    int counter = 0;
    int j = mid+1;
    
    while(counter < arraySize)
    {
        if((start<=mid)&& (data[start] < data[j]))
        {
               sortedArray[counter++] = data[start++];
        }
        else
        {
            sortedArray[counter++] = data[j++];
        }
    }
    
    for(counter=0; counter<arraySize; counter++)
    {
        data[left+counter] = sortedArray[counter];
    }
    
    delete []sortedArray;
}





int searchList(int data[], int left, int right, int val)
{
    // binary search algorithm -- divide and conquer
    // recursive implementation
    if (left < right)
    {
        int mid = left+(right-left)/2;
        
        // If the element is present at the middle itself
        if (data[mid] == val)
            return mid;
        
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (data[mid] > val)
            return searchList(data, left, mid-1, val);
        
        // Else the element can only be present in right subarray
        return searchList(data, mid+1, right, val);
    }
    
    // We reach here when element is not present in array
    return -1;
    
}




