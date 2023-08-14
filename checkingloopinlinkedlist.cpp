#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *first=NULL;
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
}int count(Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
int check(Node* r)
{
    Node*p,*q;
    p=q=r;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:q;
    }while(p&&q&&p!=q);
    if(p==q)
    return true;
    else false;
}
void Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
   if(check(first)==true)
   cout <<"Linked list having a loop";
    else cout<<"Linked list is linear";

}