#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    Node* Left;
    int Item;
    Node* Right;
};

class BST   {
    private:
        Node* root;
    protected:
        void preorderRec(Node*);
        void inorderRec(Node*);
        void postorderRec(Node*);
        Node* Delete_Item(int, Node*);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        void pre_order();
        void in_order();
        void post_order();
        void del(int);
        Node* Search(int);
        ~BST()  {
            while(root)
                del(root->Item);
        }
};

BST::BST()  {
    root = NULL;
}

bool BST::isEmpty() {
    return root == NULL;
}

void BST::insert(int data)  {
    Node* temp = new Node;
    temp->Left = NULL;
    temp->Item = data;
    temp->Right = NULL;
    if(root == NULL)
        root = temp;
    else {
        Node* t = root;
        while (t)
        {
            if(t->Item == data) {
                delete temp;
                throw "Duplicate value not allow";
            }
            else if(t->Item > data) {
                if(t->Left == NULL) {
                    t->Left = temp;
                    break;
                }
                else
                    t = t->Left;
            }
            else    {
                if(t->Right == NULL)    {
                    t->Right = temp;
                    break;
                }
                else 
                    t = t->Right;
            }
        }
    }
}

void BST::preorderRec(Node *root)   {
    if(root)
    {
        cout<<root->Item<<" ";
        preorderRec(root->Left);
        preorderRec(root->Right);
    }
}

void BST::pre_order()   {
    preorderRec(root);
    cout<<endl;
}

void BST::inorderRec(Node* root)    {
    if(root)
    {
        inorderRec(root->Left);
        cout<<root->Item<<" ";
        inorderRec(root->Right);
    }
}

void BST::in_order()    {
    inorderRec(root);
    cout<<endl;
}

void BST::postorderRec(Node* root)  {
    if(root)
    {
        postorderRec(root->Left);
        postorderRec(root->Right);
        cout<<root->Item<<" ";
    }
}

void BST::post_order()  {
    postorderRec(root);
    cout<<endl;
}

Node* BST::Delete_Item(int data, Node* t)   {
    if(t == NULL)
        return NULL;
    else if(t->Item > data) 
        t->Left = Delete_Item(data, t->Left);
    else if(t->Item < data)
        t->Right = Delete_Item(data, t->Right);
    else    {
        // No Child 
        if(t->Left == NULL && t->Right == NULL) {
            delete t;
            return NULL;
        }
        // One Child
        else if(t->Left == NULL)    {
            Node* child = t->Right;
            delete t;
            return child;
        }
        // One Child
        else if(t->Right == NULL)    {
            Node* child = t->Left;
            delete t;
            return child;
        }
        // Two Child
        else    {
            Node *prent = NULL, *child = NULL;
            child = t->Left;
            while (child->Right)
            {
                prent = child;
                child = child->Right;
            }
            t->Item = child->Item;
            if(prent == NULL)   {
                t->Left = Delete_Item(child->Item, child);
            }
            else    {
                prent->Right = Delete_Item(child->Item, child);
            }
        }
    }
    return t;
}

void BST::del(int data) {
    root = Delete_Item(data,root);
}

Node* BST::Search(int data) {
    // if(root == NULL)
    //     return NULL;
    // else    {
    Node* t = root;
    while (t)
    {
        if(t->Item == data)
            return t;
        else if(t->Item > data)
            t = t->Left;
        else
            t = t->Right;
    }
    return NULL;
}












int main()  {
    BST t1;
    t1.insert(50);
    t1.insert(80);
    t1.insert(30);
    t1.insert(45);
    t1.insert(60);
    t1.del(50);
    t1.insert(49);
    t1.in_order();
    cout<<endl;
    return 0;
}