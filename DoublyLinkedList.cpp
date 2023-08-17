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
void display(Node *p){
        while (p){
        cout<<p->data<<" ";
        p=p->next;}
        cout<<endl;
}
int length(Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
int main(){
     int A[]={1,2,3,4,5};
    create(A,5);
    cout<<"Length is: "<<length(first)<<endl;
    display(first);
    return 0;
}