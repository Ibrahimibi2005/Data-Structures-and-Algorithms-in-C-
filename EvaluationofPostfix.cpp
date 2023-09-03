#include <iostream>
#include <cstring>
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
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' )
        return 0;
    else
        return 1;
}

int Eval(char *postfix)
{
    int i = 0;
    int x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i] - 48);
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push (r);
        }
    }
    return top->data;
}
int main()
{
    char *postfix = "234*+82/-";
    cout<<"Result: "<<Eval(postfix);
}