#include <iostream>
using namespace std;

void selectionSort(int data[], int n)
{
    int min;
    int temp;
    for(int i = 0; i <n-1; i++)
    {
        min = i;
        for(int j = i +1; j<n; j++)
        {
            if(data[j] < data[min])
            {
                min= j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int dataSort[6] = {23, 5, 1, 9, 8, 12};
    selectionSort(dataSort, 6);
    printArray(dataSort, 6);
   
    return 0;
}
