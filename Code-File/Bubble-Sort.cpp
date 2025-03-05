#include<iostream>
using namespace std;

void Bubble_Sort(int arr[], int size)   {
    for(int x = 0; x<size-1; x++) {
        int temp;
        for(int z = 1; z<size-x; z++) {
            if(arr[z-1]>arr[z]) {
                temp = arr[z-1];
                arr[z-1] = arr[z];
                arr[z] = temp;
            }
        }
    }
}


int main()  {
    int arr[] = {29, 21, 10, 40, 50, 15};
    Bubble_Sort(arr,6);
    for(int x = 0; x<6; x++)
        cout<<arr[x]<<" ";
    cout<<endl;
    return 0;
}