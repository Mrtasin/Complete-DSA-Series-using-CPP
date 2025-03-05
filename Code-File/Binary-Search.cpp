#include<iostream>
using namespace std;

int BinarySearch(int arr[], int value, int lastIndex, int firstIndex = 0)   {
    
    int midIndex = (firstIndex + lastIndex) / 2;
    
    if(arr[midIndex] == value)  {
        return midIndex;
    } else if(lastIndex == firstIndex)  {
        return -1;
    } else if(arr[midIndex] < value)    {
        return BinarySearch(arr, value, lastIndex, midIndex + 1);
    } else  {
        return BinarySearch(arr, value, midIndex - 1, 0);
    }

    return -1;
}

int main()  {
    int arr[8] = {10, 20, 30, 40, 50, 60,70, 80};
    
    int tempValue;
    cout<<"Enter a Value : ";
    cin>>tempValue;
    
    int index = BinarySearch(arr,tempValue,8);

    if(index != -1)
        cout<<arr[index]<<endl;
    else
        cout<<index<<endl;
    
    return 0;
}