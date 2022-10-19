#include <malloc.h>
#include <stdio.h>
#define MAXSIZE 100
typedef int ElementType;
typedef struct QNode *Queue;
struct QNode
{
    ElementType Data[MAXSIZE];
    int front;
    int rear;
};
Queue CreateQueue();
void AddQ(Queue Q, ElementType item);
int IsFull(Queue Q);
ElementType DeleteQ(Queue Q);
int IsEmpty(Queue Q);

Queue CreateQueue()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

int IsFull(Queue Q)
{
    return ((Q->rear + 1) % MAXSIZE == Q->front);
}
void AddQ(Queue Q, ElementType item)
{
    if (IsFull(Q))
    {
        printf("队列满");
        return;
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAXSIZE;
        Q->Data[Q->rear] = item;
    }
}

int IsEmpty(Queue Q)
{
    return (Q->front == Q->rear);
}
ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("队列空");
        return 0;
    }
    else
    {
        Q->front = (Q->front + 1) % MAXSIZE;
        return Q->Data[Q->front];
    }
}
int main()
{
    Queue Q;
    Q = CreateQueue();
    AddQ(Q, 3);
    printf("3入队\n");
    AddQ(Q, 5);
    printf("5入队\n");
    AddQ(Q, 11);
    printf("11入队\n");
    printf("%d出队\n", DeleteQ(Q));
    printf("%d出队\n", DeleteQ(Q));
    return 0;
}