#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    Node* Prev;
    int Item;
    Node* Next;
};

class CDLL  {
    private:
        Node* Start;
    public:
        CDLL();
        void BegInsert(int);
        void EndInsert(int);
        Node* Serach(int);
        void MidInsert(Node*, int);
        void BegDelete();
        void EndDelete();
        void MidDelete(Node*);
        void ShowData() {
            Node* t = Start;
            do  {
                cout<<t->Item<<" ";
                t = t->Next;
            }while(t != Start);
            cout<<endl;
        }
        ~CDLL() {
            while(Start)    
                BegDelete();
        }
};

CDLL::CDLL()    {
    Start = NULL;
}

void CDLL::BegInsert(int data)  {
    Node* temp = new Node;
    temp->Item = data;
    if(Start == NULL)   {
        temp->Next = temp;
        temp->Prev = temp;
    }
    else    {
        temp->Prev = Start->Prev;
        temp->Next = Start;
        Start->Prev = temp;
        temp->Prev->Next = temp;
    }
    Start = temp;
}

void CDLL::EndInsert(int data)  {
    if(Start == NULL)
        BegInsert(data);
    else    {
        Node* temp = new Node;
        temp->Item = data;
        temp->Prev = Start->Prev;
        temp->Next = Start;
        Start->Prev->Next = temp;
        Start->Prev = temp;
    }
}

Node* CDLL::Serach(int data)    {
    if(Start == NULL)
        throw "Linked List is Empty";
    else{
        Node* t = Start;
        do
        {
            if(t->Item == data)
                return t;
            t = t->Next;
        } while (t != Start);
    }
    return NULL;
}

void CDLL::MidInsert(Node* t, int data) {
    if(Start->Prev == t)
        EndInsert(data);
    else    {
        Node* temp = new Node;
        temp->Item = data;
        temp->Prev = t;
        temp->Next = t->Next;
        t->Next->Prev = temp;
        t->Next = temp;
    }
}

void CDLL::BegDelete()  {
    if(Start == NULL)
        throw "Linked List is Empty";
    else if(Start == Start->Next)   {
        delete Start;
        Start = NULL;
    }
    else    {
        Node* t = Start;
        Start->Prev->Next = Start->Next;
        Start->Next = Start->Prev;
        Start = Start->Next;
        delete t;
    }
}

void CDLL::EndDelete()  {
    if(Start == NULL || Start == Start->Next)
        BegDelete();
    else    {
        Node* t = Start->Prev;
        t->Prev->Next = Start;
        Start->Prev = t->Prev;
        delete t;
    }
}

void CDLL::MidDelete(Node* t)   {
    if(t == Start)
        BegDelete();
    else if(t == Start->Prev)
        EndDelete();
    else    {
        t->Prev->Next = t->Next;
        t->Next->Prev = t->Prev;
        delete t;
    }
}

int main()  {
    CDLL cd1;
    cd1.BegInsert(10);
    cd1.BegInsert(20);
    cd1.BegInsert(30);
    cd1.BegInsert(40);
    cd1.EndInsert(50);
    cd1.EndInsert(60);
    cd1.EndInsert(70);
    cd1.EndDelete();
    cd1.ShowData();

    return 0;
}