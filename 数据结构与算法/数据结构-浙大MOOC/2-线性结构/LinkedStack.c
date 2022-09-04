#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElementType;
#define MAXSIZE 100
#define ERROR -1

typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 构建一个堆栈的头结点，返回该节点指针 */
Stack CreateStack() {
    Stack S;

    S = (Stack) malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

/* 判断堆栈 S 是否为空，若是返回 true，否则返回 false */
bool IsEmpty(Stack S) {
    return (S->Next == NULL);
}

// 将元素 X 压入栈 S
bool Push(Stack S, ElementType X) {
    PtrToSNode TmpCell;
    TmpCell = (PtrToSNode) malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

/* 删除并返回堆栈S的栈顶元素 */
ElementType Pop(Stack S) {
    PtrToSNode FirstCell;
    ElementType TopElem;

    if (IsEmpty(S)) {
        return ERROR
    } else {
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}