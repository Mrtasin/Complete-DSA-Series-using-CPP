namespace std {
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
                temp->Next = nullptr;
                if(top == nullptr)
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
        top = nullptr;
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
        top = nullptr;
        Node* temp = s1.top;
        while(temp) {
            push_back(temp->Item);
            temp = temp->Next;
        }
    }
}