#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MAXSIZE 100

typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

#define ERROR NULL

Position Find(List L, ElementType X)
{
    Position p = L; // p 指向 L 的第 1 个结点

    while (p && p->Data != X) {
        p = p->Next;
    }

    if (p)
        return p;
    else
        return ERROR;
}

// 带头结点的插入 —— 默认 L 有头结点
bool Insert(List L, ElementType X, Position P)
{
    Position tmp, pre;

    // 查找 P 的前一个节点
    for (pre = L; pre && pre->Next != P; pre = pre->Next)
        ;

    if (pre == NULL) // P 所指的结点不在 L 中
        return false;
    else { // 找到了 P 的前一个节点 pre
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

// 带头结点的删除 —— 默认 L 有头结点
bool Delete(List L, Position P)
{
    Position pre;

    for (pre = L; pre && pre->Next != P; pre = pre->Next)
        ;
    if (pre == NULL || P == NULL) // P 所指的结点不在 L 中
        return false;
    else { // 找到了 P 的前一个节点 pre
        pre->Next = P->Next;
        free(P);
        return true;
    }
}