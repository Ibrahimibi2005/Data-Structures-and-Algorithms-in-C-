#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node* first; 
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
void Display(Node *p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void Reverse(Node *p,Node* q){
    if(p!=NULL){
        Reverse(p->next,p);
        p->next=q;
    }
    else 
    first=q;
}
int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    Reverse(first,NULL);
    Display(first);

    }