#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    int PNo;
    int Item;
    Node* Next;
};

class p_queue   {
    private:
        Node* Start;
    public:
        p_queue();
        void insert(int, int);
        void del();
        int get_element();
        int get_h_PNumber();
        bool isEmpty();
        ~p_queue()  {
            while (Start)
                del();
        }
};

p_queue::p_queue()  {
    Start = NULL; // nullptr
}

void p_queue::insert(int data, int pno) {
    Node* temp = new Node;
    temp->PNo = pno;
    temp->Item = data;
    if(Start == NULL)   {
        temp->Next = NULL;
        Start = temp;
    }
    else    {
        Node* t = Start;
        if(Start->PNo<pno)  {
            temp->Next = Start;
            Start = temp;
        }
        else    {
            while(t->Next)  {
                if(t->Next->PNo < pno)
                    break;
                t = t->Next;
            }
            temp->Next = t->Next;
            t->Next = temp;
        }  
    }
}

void p_queue::del() {
    if(Start == NULL)
        throw "P-Queue is Empty";
    Node* t = Start;
    Start = Start->Next;
    delete t;
}

int p_queue::get_element()  {
    if(Start == NULL)
        throw "P-Queue is Empty";
    return Start->Item;
}

int p_queue::get_h_PNumber()   {
    if(Start == NULL)
        throw "P-Queue is Empty";
    return Start->PNo;
}

bool p_queue::isEmpty() {
    return Start == NULL;
}


int main()  {
    p_queue pq1;
    pq1.insert(20, 10);
    pq1.insert(40, 8);
    pq1.insert(60, 6);
    pq1.insert(90, 15);
    pq1.del();
    pq1.del();
    pq1.del();
    cout<<pq1.get_element()<<" "<<pq1.get_h_PNumber()<<endl;
    return 0;

}