#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    Node* Prev;
    int Item;
    Node* Next;
};

class Deque
{
    private:
        Node* front;
        Node* back;
    public:
        Deque();
        void push_front(int);
        void push_back(int);
        bool isEmpty();
        int get_front();
        int get_back();
        void del_front();
        void del_back();
        ~Deque()    {
            while (front)
                del_back();
        }
};

Deque::Deque()
{
    front = NULL;
    back = NULL;
}

void Deque::push_front(int data)    {
    Node* temp = new Node;
    temp->Item = data;
    temp->Next = NULL;
    temp->Prev = front;
    if(front == NULL)   {
        back = temp;
        front = temp;
    }
    else    {
        front->Next = temp;
        front = temp;
    }
}

void Deque::push_back(int data) {
    Node* temp = new Node;
    temp->Item = data;
    temp->Next = back;
    temp->Prev = NULL;
    if(back == NULL)   {
        back = temp;
        front = temp;
    }
    else    {
        back->Prev = temp;
        back = temp;
    }
}

bool Deque::isEmpty()   {
    return (front == NULL);
}

int Deque::get_front()  {
    if(isEmpty())
        throw "Deque is Empty";
    return front->Item;
}

int Deque::get_back()  {
    if(isEmpty())
        throw "Deque is Empty";
    return back->Item;
}

void Deque::del_front() {
    if(isEmpty())
        throw "Deque is Empty";
    if(front == back) {
        delete front;
        back = NULL;
        front = NULL;
    }
    else    {
        Node* t = front;
        front->Prev->Next = NULL;
        front = front->Prev;
        delete t;
    }
}

void Deque::del_back()  {
    if(isEmpty())
        throw "Deque is Empty";
    if(front == back) {
        delete back;
        back = NULL;
        front = NULL;
    }
    else    {
        Node* t = back;
        back->Next->Prev = NULL;
        back = back->Next;
        delete t;
    }
}

int main()  {
    Deque d1;
    d1.push_back(10);
    d1.push_front(20);
    d1.push_back(30);
    d1.push_front(40);
    d1.push_back(50);
    d1.push_front(60);
    d1.push_back(70);
    d1.push_front(80);
    while (!d1.isEmpty())
    {
        cout<<d1.get_back()<<" ";
        d1.del_back();
    }
    cout<<endl;
    return 0;
}