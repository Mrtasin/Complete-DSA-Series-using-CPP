#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    int Item;
    Node* Next;
};

class Stack {
    private:
        Node* top;
        void push_back(int data)    {
            Node *temp = new Node;
            temp->Item = data;
            temp->Next = NULL;
            if(top == NULL)
                top = temp;
            else    {
                Node *t = top;
                while(t->Next)
                    t = t->Next;
                t->Next = temp;
            }
        }
    public:
        Stack();
        void push(int);
        bool isEmpty();
        int peek();
        int pop();
        Stack(Stack&);
        ~Stack();
};

Stack::Stack()  {
    top = NULL;
}

void Stack::push(int data)  {
    Node* temp = new Node;
    temp->Item = data;
    temp->Next = top;
    top = temp;
}

bool Stack::isEmpty()   {
    // if(top == NULL)
    //     return true;
    // return false;

    if(top)
        return false;
    return true;
}

int Stack::peek()   {
    if(isEmpty())
        throw "Stack is Empty";
    return top->Item;
}

int Stack::pop()    {
    if(isEmpty())
        throw "Stack is Empty";
    int Data = top->Item;
    Node* t = top;
    top = top->Next;
    delete t;
    return Data;
}

Stack::~Stack() {
    while(top)
        pop();
}

Stack::Stack(Stack &s1) {
    top = NULL;
    Node* temp = s1.top;
    while(temp) {
        push_back(temp->Item);
        temp = temp->Next;
    }
}

Stack Reverse(Stack s1) {
    Stack temp;
    while(!s1.isEmpty())
        temp.push(s1.pop());
    return temp;
}

int main()  {
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(80);
    Stack s2 = Reverse(s1);
    while (!s1.isEmpty())
        cout<<s1.pop()<<" ";

    cout<<endl;

    while (!s2.isEmpty())
        cout<<s2.pop()<<" ";

    cout<<endl;
    return 0;
}