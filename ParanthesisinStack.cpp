#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};
Node *top = NULL;

void push(char x)
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
char pop()
{
    char x = -1;
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

int isBalance(char *exp)
{

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    return top == NULL ? 1 : 0;
}
int main()
{
    char *exp = "((a+b)*(c+d))";
    cout << isBalance(exp);
}