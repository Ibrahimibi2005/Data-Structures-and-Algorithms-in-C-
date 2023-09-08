#include <iostream>
using namespace std;
struct Queue
{
    int size;
    int Rear;
    int front;
    int *Q;
};
void enqueue(Queue *q, int x)
{
    if (q->Rear == q->size - 1)
    {
        cout << "queue is full";
    }
    else
    {
        q->Rear++;
        q->Q[q->Rear] = x;
    }
}
int Dequeue(Queue *q)
{
    int x = -1;
    if (q->front == q->Rear)
    {
        cout << "queue is empty";
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->Rear = -1;
    q->Q = new int[size];
}
void Display(Queue q)
{
    for (int i = q.front + 1; i <= q.Rear; i++)
    {
        cout << q.Q[i]<<" ";
    }
    cout << endl;
}
int main()
{
    Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    Display(q);
    cout << Dequeue(&q);
}