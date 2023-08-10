#include <iostream>
using namespace std;

struct Node
{
  int data;
   Node *next;
}; 
Node*first = nullptr;
void create(int A[],int n)
{
  {
    int i;
    Node*t,*last;
    first=new Node;
    first->data=A[0];
    first->next=nullptr;
    last=first;
    for(i = 1 ; i < n ; i++)
    {
      t=new Node;
      t->data = A[i];
      t->next = nullptr;
      last->next = t;
      last = t;
    }
  }
}
int count ( Node *p){
  int l=0;
  while(p){
    l++;
    p=p->next;
  }
  return l;
  }
  void sortedinsert(Node*p,int x)
  {
    struct Node *t,*q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if (first==NULL)
      first=t;
    else {
      while (p && p->data<x){
        q=p;
        p=p->next;
      }
      if (p==first){
        t->next=first;
        first=t;
      }
      else{
        t->next=q->next;
        q->next=t;
      }
    }
  }
  void Display(Node*p){
    while(p!=NULL){
      cout<<p->data<<" ";
      p=p->next;
    }
  }
int main (){
  int A[]={10,20,30,40,50};
  create(A,5);
  sortedinsert(first,45);
  Display(first);
}