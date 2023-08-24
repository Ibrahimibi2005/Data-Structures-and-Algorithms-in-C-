#include<iostream>
using namespace std;
struct stack{
    int size;
    int top;
    int * s;
}; 
void display(struct stack st){
    int i;
    for(i=st.top;i>=0;i--)
        cout<<st.s[i]<<" ";
     cout<<endl;      
}
void push(stack *st,int x){
    if (st->top==st->size-1)
    cout<<"Stack overflow"<<endl;
    else {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(stack* st){
    int x=-1;
    if (st->top==-1){
        cout<<"stack underflow\n";}
        else{
            x=st->s[st->top--];
        }
        return x;

}
int peek(stack st,int index){
    int x=-1;
    if(st.top-index<0)
    cout<<"Invalid Index"<<endl;
    x=st.s[st.top-index+1];
    return x;
}
int isEmpty(stack st){
    if(st.top==-1){
        return 1;
}
    return 0;
}
int Full(stack st){
    return st.top==st.size-1;
}
int stacktop(stack st){
    if(!isEmpty(st))
    return st.s[st.top];
    return -1;
}
void create(struct stack* st){
    
    cout<<"Enter size of stack: ";
    cin>>st->size;
    st->s=new int[st->size];  
    st->top=-1;
    
 }
 int main(){
    stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    
      
    cout<<peek(st,2)<<endl;
    cout<<stacktop(st)<<endl; 
   

    display(st);
 }