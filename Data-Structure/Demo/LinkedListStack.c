#include <malloc.h>
#include <stdio.h>
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data;
    Stack Next;
};
Stack CreateStack();
int IsEmpty(Stack S);
void Push(Stack S, ElementType item);
ElementType Pop(Stack S);

Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
int IsEmpty(Stack S)
{
    return (S->Next == NULL);
}
void Push(Stack S, ElementType item)
{
    Stack tmp;
    tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = item;
    tmp->Next = S->Next;
    S->Next = tmp;
}
ElementType Pop(Stack S)
{
    Stack First;
    ElementType TopVal;
    if (IsEmpty(S))
    {
        printf("堆栈空");
        return;
    }
    else
    {
        First = S->Next;
        S->Next = First->Next;
        TopVal = First->Data;
        free(First);
        return TopVal;
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
