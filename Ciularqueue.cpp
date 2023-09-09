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
    if ((q->Rear + 1) % q->size == q->front)
    {
        cout << "queue is full" << endl;
    }
    else
    {
        q->Rear = (q->Rear + 1) % q->size;
        q->Q[q->Rear] = x;
    }
}
int Dequeue(Queue *q)
{
    int x = -1;
    if (q->front == q->Rear)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->Rear = 0;
    q->Q = new int[size];
}
void Display(Queue q)
{
    int i = q.front + 1;
    do
    {
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    } while (i != (q.Rear + 1) % q.size);
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
    enqueue(&q, 50);
    enqueue(&q, 60);

    Display(q);
    cout << Dequeue(&q) << endl;
}