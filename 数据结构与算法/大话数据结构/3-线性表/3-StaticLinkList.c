#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* 存储空间初始分配量 */

typedef int Status;    /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char ElemType; /* ElemType类型根据实际情况而定，这里假设为char */

Status visit(ElemType c)
{
    printf("%c ", c);
    return OK;
}

/* 线性表的静态链表存储结构 */
typedef struct
{
    ElemType data;
    int cur; /* 游标(Cursor) ，为0时表示无指向 */
} Component, StaticLinkList[MAXSIZE];

/* 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针 */
Status InitList(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;
}