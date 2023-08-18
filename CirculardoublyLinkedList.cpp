#include <iostream>
using namespace std;
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
Node *Head = NULL;
void create(int A[], int n)
{
    Node *t, *Last;
    int i;
    Head = new Node;
    Head->data = A[0];
    Head->prev = NULL;
    Head->next = Head;
    Last = Head;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = Last;
        t->next = Last->next;
        Last->next = t;
        Last = t;
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
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
    cout << endl;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    cout << "Length is: " << length(Head) << endl;

    display(Head);
    return 0;
}