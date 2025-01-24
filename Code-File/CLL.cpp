#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
    int Item;
    Node* Next;
};

class CLL   {
    private:
        Node* Last;
    public:
        CLL();
        void BegInsert(int);
        void EndInsert(int);
        Node* Search(int);
        void MidInsert(Node*, int);
        void BegDelete();
        void EndDelete();
        void MidDelete(Node*);
        void ShowData() {
            Node* t = Last;
            do
            {
                t = t->Next;
                cout<<t->Item<<" ";
            } while (t != Last);
            cout<<endl;
        }
        ~CLL()  {
            while(Last)
                BegDelete();
        }
};

CLL::CLL()  {
    Last = NULL;
}

void CLL::BegInsert(int data)   {
    Node* temp = new Node;
    temp->Item = data;
    if(Last == NULL)    {
        temp->Next = temp;
        Last = temp;
    }
    else    {
        temp->Next = Last->Next;
        Last->Next = temp;
    }
}

void CLL::EndInsert(int data)   {
    if(Last == NULL)
        BegInsert(data);
    else {
        Node* temp = new Node;
        temp->Item = data;
        temp->Next = Last->Next;
        Last->Next = temp;
        Last = temp;
    }
}

Node* CLL::Search(int data) {
    Node *t = Last;
    if(Last == NULL)
        return NULL;
    do{
        if(t->Item == data)
            return t;
        t = t->Next;
    }while(t != Last);
    return NULL;
}

void CLL::MidInsert(Node* t, int data)  {
    Node* temp = new Node;
    temp->Item = data;
    temp->Next = t->Next;
    t->Next = temp;
}

void CLL::BegDelete()   {
    if(Last == NULL)
        throw "Empty Linked List";
    if(Last->Next == Last)  {
        delete Last;
        Last = NULL;
    }
    else    {
        Node* t = Last->Next;
        Last->Next = t->Next;
        delete t;
    }
}

void CLL::EndDelete()   {
    if(Last == NULL || Last == Last->Next)
        BegDelete();
    else    {
        Node* t = Last;
        while(Last != t->Next)
            t = t->Next;
        t->Next = Last->Next;
        delete Last;
        Last = t;
    }
}

void CLL::MidDelete(Node* t)    {
    if(t == t->Next)
        BegDelete();
    else if(t == Last)
        EndDelete();
    else    {
        Node* temp = Last;
        while(temp->Next != t)  
            temp = temp->Next;
        temp->Next = t->Next;
        delete t;
    }
}

int main()  {
    CLL c1;
    c1.BegInsert(10);
    c1.BegInsert(20);
    c1.BegInsert(30);
    c1.BegInsert(40);
    c1.MidInsert(c1.Search(30), 35);
    c1.EndInsert(100);
    c1.ShowData();

    return 0;
}