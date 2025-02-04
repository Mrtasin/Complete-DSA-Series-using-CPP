#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
    int Item;
    Node* Next;
};

class Queue {
    private:
        Node* front;
        Node* back;
    public:
        Queue();
        void push_back(int);
        bool isEmpty();
        int get_back();
        int get_front();
        void Delete_front();
        ~Queue()    {
            while (front)
                Delete_front();
        }
        int size();
};

Queue::Queue()  {
    front = NULL;
    back = NULL;
}

void Queue::push_back(int data) {
    Node* temp = new Node;
    temp->Item = data;
    temp->Next = NULL;
    if(front == NULL)   {
        back = temp;
        front = temp;
    }
    else    {
        back->Next = temp;
        back = temp;
    }
}

bool Queue::isEmpty()   {
    return (back == NULL);
}

int Queue::get_back()   {
    if(isEmpty())
        throw "Queue is Empty";
    return back->Item;
}

int Queue::get_front()   {
    if(isEmpty())
        throw "Queue is Empty";
    return front->Item;
}

void Queue::Delete_front()  {
    if(isEmpty())
        throw "Queue is Empty";
    if(front == back)   {
        delete front;
        front = NULL;
        back = NULL;
    }
    else    {
        Node* t = front;
        front = front->Next;
        delete t;
    }
}

int Queue::size()   {
    int count = 0;
    for(Node* t = front; t; count++, t = t->Next);
    return count;
}

int main()  {
    Queue q1;
    q1.push_back(10);
    q1.push_back(20);
    q1.push_back(30);
    q1.push_back(40);
    q1.push_back(50);
    while(!q1.isEmpty())  {
        cout<<q1.get_front()<<" ";
        q1.Delete_front();
    }
    cout<<endl;
    return 0;
}