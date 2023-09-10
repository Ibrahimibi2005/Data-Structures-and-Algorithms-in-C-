#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node *front=NULL;
Node*Rear=NULL;
void enqueue(int x){
    Node* t;
    t= new Node;
  
    if(t==NULL)
       cout<<"queue is full";
    else {
        t->data=x;
        t->next=NULL;
        if(front ==NULL){
            front =Rear=t;
        }
        else{
            Rear->next=t;
            Rear=t;
        }
    }
}
int Dequeue(){
    int x=-1;
    Node*t;
    if(front==NULL){
        cout<<"Queue is empty";
    }
    else{
        x=front->data;
        t=front;
        front=front->next;
        delete t;
    }
    return x;
}
void Display(){
    Node*p=front;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    Display(); 
    cout<<Dequeue();
}