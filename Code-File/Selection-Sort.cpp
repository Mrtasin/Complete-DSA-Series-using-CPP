#include<iostream>
using namespace std;

int findMinValueIndex(int arr[], int firstIndex, int lastIndex) {

    int minValue = arr[firstIndex];
    int minValueIndex = firstIndex;

    for(firstIndex++; firstIndex<=lastIndex; firstIndex++)  {

        if(minValue > arr[firstIndex])  {
            
            minValue = arr[firstIndex];
            minValueIndex = firstIndex;
        }
    }
    return minValueIndex;
}

void swapArrayElement(int arr[], int firstIndex, int lastIndex) {
    
    int temp;

    temp = arr[firstIndex];
    arr[firstIndex] = arr[lastIndex];
    arr[lastIndex] = temp;
}

void Selection_sort(int arr[], int size)    {
    int minValueIndex;

    for(int x = 0; x<size-1; x++) {
        
        minValueIndex = findMinValueIndex(arr, x, size-1);
        swapArrayElement(arr, x, minValueIndex);
    }
}

int main()  {
    int arr[] = {23,12,45,43,21,56,43,65,28,11};
    Selection_sort(arr,10);
    for(int x = 0; x<10; x++)
        cout<<arr[x]<<" ";
    cout<<endl;
    return 0;
}

