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

void display(Node *p){
    
    do{
        cout<<p->data<<' ';
        p=p->next;
    }while(p!=Head);
    cout<<endl;
}
int main ()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(Head);
    return 0;
}