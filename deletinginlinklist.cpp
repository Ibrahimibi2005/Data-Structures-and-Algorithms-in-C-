#include <iostream>
using namespace std;

struct Node
{
  int data;
   Node *next;
}; 
Node*first = nullptr;

void create(int A[], int n)
{
  int i;
  Node *t, *last;
  first = new  Node;
  first->data = A[0];
  first->next = nullptr;
  last = first;
  for (i = 1; i < n; i++) 
  {
    t = new  Node;
    t->data = A[i];
    t->next =nullptr;
    last->next = t;
    last = t;
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
  int Delete(Node*p,int index){
    Node*q;
    int x=1;
    if(index < 1||index > count(p))
     return -1;
    if (index==1){
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    } 
    else{
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
  }
    void Display(Node* p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
  int A[] = {3, 5, 7, 9, 11};
  create(A,5 );
  
 cout<<"Deleted Element: "<< Delete(first,4)<<endl; 
  Display(first);

  return 0;
}