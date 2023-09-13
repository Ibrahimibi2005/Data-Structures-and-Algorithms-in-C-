#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
public:
    Node *top;
    Stack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        Node *temp = new Node;
        if (temp == nullptr)
        {
            cout << "Stack is full\n";
            return;
        }
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        Node *temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

void enqueue(Stack &s1, Stack &s2, int x)
{
    s1.push(x);
}

int dequeue(Stack &s1, Stack &s2)
{
    if (s2.isEmpty())
    {
        if (s1.isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
    }
    return s2.pop();
}

void display(Stack &s)
{
    Node *p = s.top;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack s1, s2;

    enqueue(s1, s2, 10);
    enqueue(s1, s2, 20);
    enqueue(s1, s2, 30);
    enqueue(s1, s2, 40);

    dequeue(s1, s2);
    display(s2); 
    
    return 0;
}
