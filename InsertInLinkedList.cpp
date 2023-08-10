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
void insert(Node* p, int index, int x)
{
    Node* t;
    int i;

    if (index < 0 || index > count(p))
        return;

    t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
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
  int A[] = {3, 5, 7};
  create(A,3);
  Display(first);
  cout<<endl;
  insert(first,3,10);
  Display(first);
 
}
