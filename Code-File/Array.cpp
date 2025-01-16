#include<iostream>
using namespace std;

class Array {
    private:
        int last_index;
        int capacity;
        int *ptr;
    public:
        Array(int);
        bool isEmpty();
        void append(int);
        bool isFull();
        void insert(int, int);
        void del(int);
        void edit(int,int);
        int getItem(int);
        int count();
        int find(int);
        void showdata() {
            for(int x = 0; x<=last_index; x++)
                cout<<ptr[x]<<" ";
            cout<<endl;
        }
        ~Array()    {
            delete []ptr;
        }
};

Array::Array(int size)  {
    capacity = size;
    last_index = -1;
    ptr = new int[size];
}

bool Array::isEmpty()   {
    if(last_index == -1)
        return true;
    return false;
}

void Array::append(int data)    {
    if(isFull())
        throw  "Array is Full";
    last_index++;
    ptr[last_index] = data;
}

bool Array::isFull()    {
    if(capacity == last_index + 1)
        return true;
    return false;
}

void Array::insert(int index, int data) {
    if(isFull())
        throw  "Array is Full";
    if(0<=index && last_index+1 >= index)   {
        for(int x = last_index; x>=index; x--)
            ptr[x+1] = ptr[x];
        ptr[index] = data;
        last_index++;
    }
    else
        throw "invalid index";
}

void Array::del(int index)  {
    if(isEmpty())
        throw "Array is Empty";
    if(0<=index && last_index+1 >= index)   {
        for(int x = index; x<last_index; x++)
            ptr[x] = ptr[x+1];
        last_index--;
    }
    else
        throw "invalid index";
}

void Array::edit(int index, int data)   {
    if(isEmpty())
        throw "Array is Empty";
    if(0<=index && last_index >= index)
        ptr[index] = data;
    else
        throw "invalid index";
}

int Array::getItem(int index)   {
    if(isEmpty())
        throw "Array is Empty";
    if(0<=index && last_index >= index)
        return ptr[index];
    else
        throw "invalid index";
}

int Array::count()  {
    return last_index+1;
}

int Array::find(int data)   {
    if(isEmpty())
        throw "Array is Empty";
    for(int x = 0; x<last_index; x++)   
        if(ptr[x] == data)
            return x;
    return -1;
}


int main()  {
    Array arr(10);
    try{
        arr.append(10);
        arr.append(20);
        arr.append(30);
        arr.append(40);
        arr.append(40);
        arr.append(40);
        arr.append(40);
        arr.append(40);
        arr.append(40);
        arr.append(40);
        arr.append(40);
        arr.append(40);
        arr.append(40);
        arr.append(40);
    }
    catch(const char *ch)   {
        cout<<ch<<endl;
    }

    arr.del(1);
    arr.insert(5, 100);
    arr.showdata();

    return 0;
}