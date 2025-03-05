#include<iostream>
using namespace std;

void Insertion_Sort(int arr[], int size)    {
    int tempData;
    int tempArraySize = 0;

    for(int index = 1; index<size; index++, tempArraySize++) {
        tempData = arr[index];
        int x;

        for(x = tempArraySize; x >= 0; x--) {
            if(arr[x] > tempData) {
                arr[x+1] = arr[x];
            }
            else    {
                break;
            }
        }
        arr[x+1] = tempData;
    }
}


int main()  {
    int arr[] = {12,32,43,4,15,36,76,85};
    Insertion_Sort(arr, 8);
    for(int x = 0; x < 8; x++)
        cout<<arr[x]<<" ";
    cout<<endl;
    return 0;
}