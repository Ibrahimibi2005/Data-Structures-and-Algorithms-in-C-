#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int x)
    {
        Node *t = new Node;
        if (t == NULL)
        {
            cout << "Stack is Full";
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
        int x = 1;
        Node *t;
        if (top == NULL)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            x = top->data;
            t = top;
            top = top->next;
            delete t;
        }
        return x;
    }
    void Display()
    {
        Node *p = top;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.Display();
    cout << stk.pop();
}