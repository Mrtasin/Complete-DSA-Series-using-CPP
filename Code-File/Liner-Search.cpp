#include<iostream>
using namespace std;

int LinerSearch(int arr[], int value, int size) {
    
    for(int index = 0; index < size; index++)   {

        if(arr[index] == value) {
            return index;
        }
    }
    
    return -1;
}