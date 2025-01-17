#include<iostream>
using namespace std;

class DynamicArray  {
    private:
        int capacity;
        int last_index;
        int *ptr;
    public:
        DynamicArray(int);
        void double_Array();
        void half_Array();
        int size();
        bool isEmpty();
        void append(int);
        bool isFull();
        void insert(int, int);
        void edit(int, int);
        void del(int);
        int getItem(int);
        int count();
        int find(int);
        ~DynamicArray() {
            delete []ptr;
        }
        void ShowData() {
            for(int x = 0; x<=last_index; x++)
                cout<<ptr[x]<<" ";
            cout<<endl;
        }
};

DynamicArray::DynamicArray(int size)    {
    capacity = size;
    last_index = -1;
    ptr = new int[size];
}

void DynamicArray::double_Array()   {
    capacity *= 2; // capacity = capacity * 2;
    int *temp = new int[capacity];
    for(int x = 0; x<=last_index; x++)  {
        temp[x] = ptr[x];
    }
    delete ptr;
    ptr = temp;
}

void DynamicArray::half_Array() {
    capacity /= 2; // capacity = capacity / 2;
    int *temp = new int[capacity];
    for(int x = 0; x<=last_index; x++)  {
        temp[x] = ptr[x];
    }
    delete ptr;
    ptr = temp;
}

int DynamicArray::size()    {
    return capacity;
}

bool DynamicArray::isEmpty()    {
    if(last_index == -1)
        return true;
    return false;
}

void DynamicArray::append(int data) {
    if(isFull())
        double_Array();
    last_index++;
    ptr[last_index] = data;
}

bool DynamicArray::isFull() {
    if((capacity - 1) == last_index)
        return true;
    return false;
}

void DynamicArray::insert(int index, int data)  {
    if(isFull())
        double_Array();
    last_index++;
    if(index >= 0 && index <= last_index)   {
        for(int x = last_index; index<x; x--)
            ptr[x] = ptr[x-1];
        ptr[index] = data;
    }
    else
        throw "Invalid Index";
}

void DynamicArray::edit(int index, int data)    {
    if(index >= 0 && index <= last_index)
        ptr[index] = data;
    else
        throw "Invalid Index";
}

void DynamicArray::del(int index)   {
    if(isEmpty())
        throw "Array is empty";
    if(index >= 0 && index <= last_index)   {
        for(int x = index; x<last_index; x++)
            ptr[x] = ptr[x+1];
        last_index--;
        if((capacity / 2) > last_index )
            half_Array();
    }
    else
        throw "Invalid Index";
}

int DynamicArray::getItem(int index)    {
    if(isEmpty())
        throw "Array is empty";
    if(index >= 0 && index <= last_index)
        return ptr[index];
    else
        throw "Invalid Index";
}

int DynamicArray::count()   {
    return (last_index + 1);
}

int DynamicArray::find(int data)  {
    if(isEmpty())
        throw "Array is empty";
    for(int x = 0; x<=last_index; x++)
        if(ptr[x] == data)
            return x;
    return -1;
}

int main()  {
    DynamicArray d1(1);
    d1.append(10);
    d1.append(20);
    d1.append(30);
    d1.append(40);
    d1.del(1);
    d1.insert(3, 50);
    d1.edit(0,100);
    d1.del(1);
    d1.ShowData();
    cout<<"capacity : "<<d1.size()<<endl;
    return 0;
}