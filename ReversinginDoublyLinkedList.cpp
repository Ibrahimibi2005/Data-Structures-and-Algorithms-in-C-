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
void Reverse(Node *p){
    Node* temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
      if(p!=NULL && p->next==NULL)
       first=p;
    }

}

void display(Node *p){
        while (p!=NULL){
        cout<<p->data<<" ";
        p=p->next;}
        cout<<endl;
}

int main(){
     int A[]={1,2,3,4,5};
    create(A,5); 
    cout<<"Length is: "<<length(first)<<endl;
    Reverse(first);
    display(first);
    return 0;
}