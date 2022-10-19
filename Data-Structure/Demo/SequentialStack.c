#include <malloc.h>
#include <stdio.h>
#define MAXSIZE 100
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data[MAXSIZE];
    int Top;
};
Stack CreateStack();
int IsFull(Stack S);
int IsEmpty(Stack S);
void Push(Stack S, ElementType item);
ElementType Pop(Stack S);

Stack CreatStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Top = -1;
    return S;
}
int IsFull(Stack S)
{
    return (S->Top == MAXSIZE - 1);
}
int IsEmpty(Stack S)
{
    return (S->Top == -1);
}
void Push(Stack S, ElementType item)
{
    if (IsFull(S))
    {
        printf("堆栈满");
        return;
    }
    else
    {
        S->Top++;
        S->Data[S->Top] = item;
        return;
    }
}
ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("堆栈空");
    }
    else
    {
        ElementType val = S->Data[S->Top];
        S->Top--;
        return val;
    }
}
int main()
{
    Stack S;
    S = CreateStack();
    printf("5入栈\n");
    Push(S, 5);
    printf("7入栈\n");
    Push(S, 7);
    printf("66入栈\n");
    Push(S, 66);
    printf("%d出栈\n", Pop(S));
    printf("%d出栈\n", Pop(S));
    return 0;
}