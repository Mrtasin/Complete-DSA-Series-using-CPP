#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    Node *Prev;
    int Item;
    Node* Next;
};

class DLL   {
    private:
        Node* Start;
    public:
        DLL();
        void BegInsert(int);
        void EndInsert(int);
        Node* Search(int);
        void MidInsert(Node*, int);
        void BegDelete();
        void EndDelete();
        void MidDelete(Node*);
        void ShowData() {
            for(Node* t = Start; t; t = t->Next)
                cout<<t->Item<<" ";
            cout<<endl;
        }
        ~DLL()  {
            while(Start)
                BegDelete();
        }
};

DLL::DLL()  {
    Start = NULL;
}

void DLL::BegInsert(int data)   {
    Node *temp = new Node;
    temp->Item = data;
    temp->Prev = NULL;
    temp->Next = Start;
    if(Start != NULL)
        Start->Prev = temp;
    Start = temp;
}

void DLL::EndInsert(int data)   {
    Node *temp = new Node;
    temp->Item = data;
    temp->Next = NULL;
    Node *t = Start;
    while(t->Next)
        t = t->Next;
    temp->Prev = t;
    if(Start == NULL)
        Start = temp;
    else
        t->Next = temp;
}

Node* DLL::Search(int data) {
    Node* t = Start;
    while(t)    {
        if(t->Item == data)
            return t;
        t = t->Next;
    }
    return NULL;
}

void DLL::MidInsert(Node* t, int data)  {
    if(t->Next == NULL)
        EndInsert(data);
    else    {
        Node *temp = new Node;
        temp->Item = data;
        temp->Prev = t;
        temp->Next = t->Next;
        t->Next->Prev = temp;
        t->Next = temp;
    }
}

void DLL::BegDelete()   {
    if(Start == NULL)
        throw "List is empty";
    Node* t = Start;    
    if(Start->Next == NULL)
        Start = NULL;
    else{
        Start->Next->Prev = NULL;
        Start = Start->Next;
    }
    delete t;
}

void DLL::EndDelete()   {
    if(Start == NULL || Start->Next == NULL)
        BegDelete();
    else{
        Node* t = Start;
        while (t->Next)
            t = t->Next;
        t->Prev->Next = NULL;
        delete t;
    }
}

void DLL::MidDelete(Node* t)    {
    if(t->Prev == NULL)
        BegDelete();
    else if(t->Next == NULL)
        EndDelete();
    else    {
        t->Prev->Next = t->Next;
        t->Next->Prev = t->Prev;
        delete t;
    }
}

int main()  {
    DLL d1;
    d1.BegInsert(10);
    d1.BegInsert(20);
    d1.BegInsert(30);
    d1.BegInsert(40);
    d1.BegInsert(50);
    d1.MidDelete(d1.Search(50));
    d1.ShowData();

    return 0;
}