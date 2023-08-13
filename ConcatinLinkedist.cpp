#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *first=NULL,*second=NULL,*third=NULL;
void create(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}
void create2(int A[],int n){
    int i;
    Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = nullptr;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

int count(Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
void Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void Concat(Node* p,Node* q){
    third=p;
    while(p->next!=NULL)
        p=p->next;
        p->next=q;
        
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int B[]={1,2,3,5,6};
    create(A, 5);
    create2(B,5);
    Concat(second,first);
    Display(third);
}
