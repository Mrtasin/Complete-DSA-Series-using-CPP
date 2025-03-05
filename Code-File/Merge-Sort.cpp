#include<iostream>
using namespace std;

void mergeTwoSortedArray(int arr[], int firstIndex, int midIndex, int lastIndex)    {
    
}

void mergeSort(int arr[], int firstIndex, int lastIndex)    {
    
    if(firstIndex<lastIndex)    {
        int midIndex = (firstIndex + lastIndex) / 2;
        mergeSort(arr, firstIndex, midIndex);
        mergeSort(arr, midIndex+1, lastIndex);
        mergeTwoSortedArray(arr, firstIndex, midIndex, lastIndex);
    }
}