#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *top = NULL;

void push(int x)
{
    Node *t;
    t = new Node;
    if (t == NULL)
    {
        cout << "Stack is Full\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int pop()
{
    int x = -1;
    struct Node *t;
    if (top == NULL)
    {
        cout << "stack is Empty";
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    Display();
    cout << pop();
}