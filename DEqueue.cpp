#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *front = nullptr;
Node *Rear = nullptr;

void enqueue(int x)
{
    Node *t = new Node;

    if (t == nullptr)
        cout << "Queue is full";
    else
    {
        t->data = x;
        t->next = nullptr;
        t->prev = nullptr;
        if (front == nullptr)
        {
            front = Rear = t;
        }
        else
        {
            Rear->next = t;
            t->prev = Rear;
            Rear = t;
        }
    }
}

void Fenqueue(int x)
{
    Node *t = new Node;

    if (t == nullptr)
        cout << "Queue is full";
    else
    {
        t->data = x;
        t->next = nullptr;
        t->prev = nullptr;
        if (front == nullptr)
        {
            front = Rear = t;
        }
        else
        {
            t->next = front;
            front->prev = t;
            front = t;
        }
    }
}

int Dequeue()
{
    int x = -1;
    Node *t;
    if (front == nullptr)
    {
        cout << "Queue is empty";
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        if (front != nullptr)
        {
            front->prev = nullptr;
        }
        delete t;
    }
    return x;
}

int RDequeue()
{
    int x = -1;
    Node *t;
    if (Rear == nullptr)
    {
        cout << "Queue is empty";
    }
    else
    {
        x = Rear->data;
        t = Rear;
        Rear = Rear->prev;
        if (Rear != nullptr)
        {
            Rear->next = nullptr;
        }
        delete t;
    }
    return x;
}

void Display()
{
    Node *p = front;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    Display();
    cout << RDequeue() << endl;
    Fenqueue(10);
    Fenqueue(20);
    Fenqueue(30);
    Display();
}
