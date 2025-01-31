#include<iostream>
#include "Stack.h"
using namespace std;


bool Palindrome(int data)   {
    int temp_data = data; // 12345
    Stack s1;  // 54321
    while(temp_data)    {
        s1.push(temp_data%10);
        temp_data /= 10; // temp_data = temp_data / 10;
    }
    while(!s1.isEmpty())    {
        if(data%10 != s1.pop())
            return false;
        data /= 10;
    }
    return true;
}

int main()  {
    int data ;
    cout<<"Enter a number : ";
    cin>>data;
    if(Palindrome(data))
        cout<<"This is a Palindrome number"<<endl;
    else
        cout<<"This is a Not Palindrome Number"<<endl;
    return 0;
}