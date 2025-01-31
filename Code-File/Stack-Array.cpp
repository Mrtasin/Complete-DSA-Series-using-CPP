#include<iostream>
#include<stdio.h>
using namespace std;

class Stack    {
    private:
        int capacity;
        int top;
        int* ptr;
    public:
        Stack(int);
        bool isFull();
        bool isEmpty();
        void push(int);
        int peek();
        int pop();
        ~Stack()    {
            delete []ptr;
        }
};

Stack::Stack(int size)  {
    capacity = size;
    top = -1;
    ptr = new int[size];
}

bool Stack::isFull()    {
    if(capacity == top+1)   
        return true;
    return false;
}

bool Stack::isEmpty()    {
    if(top == -1)   
        return true;
    return false;
}

void Stack::push(int data)  {
    if(isFull())
        throw "Stack is Full";
    ptr[++top] = data;
}

int Stack::peek()   {
    if(isEmpty())
        throw "Stack is Empty";
    return ptr[top];
}

int Stack::pop()    {
    if(isEmpty())
        throw "Stack is Empty";
    // int data = ptr[top];
    // top--;
    // return data;

    return (ptr[top--]);
}

int main()  {
    Stack s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    while(!s1.isEmpty())
        cout<<s1.pop()<<" ";
    cout<<endl;
    return 0;
}