#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *first;
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
void Mid(){
    Node* p,*q;
    p=q=first;
    while (q){
        q=q->next;
        if(q){
            q=q->next;
            if(q){
                p=p->next;
            }
        }
    }
    cout<<"MID: "<<p->data;
}
void Display(Node *p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main(){
    int A[]={1,2,3,4,5};
    create(A ,5);
    Mid();
    
}