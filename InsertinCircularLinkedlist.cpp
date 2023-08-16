#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *Head = NULL;
void create(int A[], int n)
{
    Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
int length(Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void display(Node *p)
{

    do
    {
        cout << p->data << ' ';
        p = p->next;
    } while (p != Head);
    cout << endl;
}
void insert(Node *p, int index, int x)
{
    Node *t;
    int i;
    if (index >= 0 || index > length(Head))
    {
        if (index == 0)
        {
            t = new Node;
            t->data = x;
            if (Head == NULL)
            {
                Head = t;
                Head->next = Head;
            }
            else
            {
                while (p->next != Head)
                    p = p->next;
                p->next = t;
                t->next = Head;
                Head = t;
            }
        }
        else
        {
            for (i = 0; i < index - 1; i++)
                p = p->next;
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    insert(Head, 0, 10);
    display(Head);
    return 0;
}