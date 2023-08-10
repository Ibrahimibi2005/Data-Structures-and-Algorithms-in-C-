#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *first = nullptr;

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
int Sort(Node*p){
int x=-32768;
 p=first;
while(p!=NULL){
    if(p->data<x)
    return 0;
    x=p->data;
    p=p->next;
}
return 1;
}
void Display(Node *p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main (){
    int A[5]={10,20,30,40,50};
    create(A,5);
    if(Sort(first))
    cout<<"Sorted\n";
    else
    cout<<"Not Sorted\n";
    Display(first);
    return 0;
}