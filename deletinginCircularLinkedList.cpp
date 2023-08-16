#include<iostream>
using namespace std;

struct Node {
    int data ;
    Node *next;
};
Node * Head=NULL;
void create(int A[],int n){
    Node *t,* last;
    Head =new Node;
    Head->data=A[0];
    Head->next=Head;
    last =Head;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
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
int Delete(Node* p ,int index)
{
    Node*q;
    int x;
    if(index < 0||index > length(Head))
    return -1;
        if(index==1){
         while (p->next!=Head)p=p->next;
         x=Head->data;
         if(Head==p){
            delete Head;
            Head=NULL;
         }
         else {
            p->next=Head->next;
            delete Head;
            Head=p->next;
         }
        }
        else {
            for(int i=0;i<=index-2;i++)p=p->next;
            q=p->next;
            p->next=q->next;
            x =q->data;
            delete q;
            
        }
        return x;
    }


int main ()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    Delete(Head,3);
    display(Head);
    return 0;
}