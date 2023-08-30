#include <iostream>
#include<cstring>
using namespace std;
struct Node
{
    char data;
    Node *next;
};
Node *top = NULL;

void push(char x)
{
    Node *t;
    t = new Node;
    if (t == NULL)
    {
        cout << "Stack is Full\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    char x = -1;
    struct Node *t;
    if (top == NULL)
    {
        cout << "stack is Empty";
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

 int pre(char x){
    if (x=='+'||x=='-')
     return 1;
    else if(x=='*'||x=='/')
     return 2;
    return 0; 
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    else
   return 1;
}
char* InToPost(char *infix)
{
    char*postfix;
    int len = strlen(infix) ;
    postfix=new char[len+1];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i]))
           postfix[j++]=infix[i++];
        else 
        {
            if (pre(infix[i]) > pre(top->data) || top == NULL)
            push(infix[i++]);
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
    postfix[j++]=pop();
    postfix[j]='\0';

    return postfix;
    }
int main()
{
    char *infix ="a+b*c";
    push('#');
    char *postfix=InToPost(infix);
    cout<<postfix;
}