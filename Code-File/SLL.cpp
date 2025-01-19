#include<iostream>
#include<stdio.h>
using namespace std;

// class Node  {
//     public:
//         int Item;
//         Node *Next;
// };

struct Node  {
    int Item;
    Node *Next;
};

class SLL   {
    private:
        Node* start;
    public:
        SLL();
        void Beginsert(int);
        void Endinsert(int);
        Node* Search(int);
        void Midinsert(Node* ,int);
        void BegDelete();
        void EndDelete();
        void MidDelete(Node*);
        ~SLL();
};

SLL::SLL()  {
    start = NULL;
}

void SLL::Beginsert(int data)   {
    Node* temp = new Node;
    temp->Item = data;
    temp->Next = start;
    start = temp;
}

void SLL::Endinsert(int data)   {
    if(start == NULL)
        Beginsert(data);
    else{
        Node* temp = new Node;
        temp->Item = data;
        temp->Next = NULL;
        Node *t = start;
        // for( ; t->Next; t = t->Next); 
        while(t->Next)
            t = t->Next;
        t->Next = temp;
    }  
}

Node* SLL::Search(int data) {
    for(Node *t = start; t; t= t->Next)
        if(t->Item == data)
            return t;
    return NULL;
}

void SLL::Midinsert(Node *t, int data)  {
    Node *temp = new Node;
    temp->Item = data;
    temp->Next = t->Next;
    t->Next = temp;
}

void SLL::BegDelete()   {
    if(start == NULL)
        throw "Empty List";
    Node *t = start;
    start = t->Next;
    delete t;
}

void SLL::EndDelete()   {
    if(start == NULL || start->Next == NULL)
        BegDelete();
    else    {
        Node *td,*t = start;
        while(t->Next->Next)
            t = t->Next;
        td = t->Next;
        t->Next = NULL;
        delete td;
    }
}

void SLL::MidDelete(Node *t)    {
    if(start == t)
        BegDelete();
    else{
        Node *temp = start;
        for(; temp->Next != t; temp = temp->Next);
        temp->Next = t->Next;
        delete t;
    }
}

SLL::~SLL() {
    while(start)
        BegDelete();
}