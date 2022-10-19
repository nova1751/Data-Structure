#include <malloc.h>
#include <stdio.h>
typedef int ElementType;
typedef struct QNode *Queue;
struct Node
{
    ElementType Data;
    struct Node *Next;
};
struct QNode
{
    struct Node *rear;
    struct Node *front;
};
Queue CreateQueue();
void AddQ(Queue Q, ElementType item);
ElementType DeleteQ(Queue Q);
int IsEmpty(Queue Q);

Queue CreateQueue()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}
int IsEmpty(Queue Q)
{
    return (Q->front == NULL);
}
void AddQ(Queue Q, ElementType item)
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->Data = item;
    node->Next = NULL;
    if (Q->rear == NULL)
    {
        Q->rear = node;
        Q->front = node;
    }
    else
    {
        Q->rear->Next = node;
        Q->rear = node;
    }
}
ElementType DeleteQ(Queue Q)
{
    struct Node *FrontCell;
    ElementType FrontElem;
    if (IsEmpty(Q))
    {
        printf("队列空");
        return 0;
    }
    FrontCell = Q->front;
    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = NULL;
    }
    else
    {
        Q->front = Q->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}
int main()
{
    Queue Q;
    Q = CreateQueue();
    printf("入队5\n");
    AddQ(Q, 5);
    printf("入队4\n");
    AddQ(Q, 4);
    printf("入队3\n");
    AddQ(Q, 3);
    printf("出队%d\n", DeleteQ(Q));
    printf("出队%d\n", DeleteQ(Q));
    printf("出队%d\n", DeleteQ(Q));
    printf("%d\n", DeleteQ(Q));
    return 0;
}
