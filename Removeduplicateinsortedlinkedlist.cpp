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
void DelDuplicate(Node*p){
    Node* q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else 
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
} 
int main(){
   int A[]={10,20,20,20,30,40,40,40,50};
   create(A,9);
   DelDuplicate(first);
   Display(first);
}