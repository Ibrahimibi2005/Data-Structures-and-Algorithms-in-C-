#include<iostream>
using namespace std;
struct Node{
   struct Node* prev;
   int data;
   struct Node* next;    
};
Node* first=NULL;
void create(int A[],int n){
       Node* t, * Last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    Last = first;
    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->prev = Last;
        t->next = NULL;
        Last->next = t;
        Last = t;
    }
}
int length(Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
int Delete(Node* p,int index){
    struct Node* q;
    int x=-1,i;
    if(index < 1||index > length(p))
    return -1;
    if(index==1){
         first=first->next;
         if(first)first->prev=NULL;
         x=p->data;
         delete p;
    }
    else{
        for(i=0 ; i<index ; i++)
        p=p->next;
        p->prev->next=p->next;
        if(p->next)
        p->next->prev=p->prev;
        x=p->data;
        delete p;

    }
    return x;

}
void display(Node *p){
        while (p){
        cout<<p->data<<" ";
        p=p->next;}
        cout<<endl;
}

int main(){
     int A[]={1,2,3,4,5};
    create(A,5); 
    cout<<"Length is: "<<length(first)<<endl;
    Delete(first,1);
    display(first);
    return 0;
}