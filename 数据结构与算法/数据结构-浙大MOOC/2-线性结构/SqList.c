#include <stdbool.h>
#include <stdio.h>

typedef int ElementType;
#define MAXSIZE 100
#define ERROR -1

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position last;
};

// 初始化
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->last = -1;

    return L;
}

// 查找
Position Find(List L, ElementType X)
{
    Position i = 0;

    while (i <= L->last && L->Data[i] != X)
        i++;
    if (i > L->last)
        return ERROR; // 如果没找到，返回错误信息
    else
        return i; // 找到后返回的是存储位置
}

// 插入 —— 在 L 的指定位置 P 前插入一个新元素 X
bool Insert(List L, ElementType X, Position P)
{
    Position i;

    if (L->last == MAXSIZE - 1)
        // 表空间已满，不能插入
        return false;

    if (P < 0 || P > L->last + 1) // 检查插入位置的合法性
        return false;

    for (i = L->last; i >= P; i--)
        L->Data[i + 1] = L->Data[i]; // 将位置 P 及以后的元素顺序向后移动

    L->Data[P] = X; // 新元素插入
    L->last++;      // Last 仍指向最后元素
    return true;
}

// 删除 —— 从 L 中删除指定位置 P 的元素
bool Delete(List L, Position P)
{
    Position i;

    if (P < 0 || P > L->last) // 检查空表及删除位置的合法性
        return false;

    for (i = P + 1; i <= L->last; i++) {
        L->Data[i - 1] = L->Data[i]; // 将位置P+1及以后的元素顺序向前移动
    }
    L->last--; // Last仍指向最后元素
    return true;
}