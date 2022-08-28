#include "node.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: 实现 tail
typedef struct _list {
    Node *head;
    Node *tail;
} List;

void add(List *pList, int number);
void print(List *pList);

int main(int argc, char const *argv[])
{
    List list;
    int number;
    list.head = list.tail = NULL;
    do {
        scanf("%d", &number);
        if (number != -1) {
            add(&list, number);
        }
    } while (number != -1);
    print(&list);
    scanf("%d", &number);
    search(&list, number);
    return 0;
}

void add(List *pList, int number)
{
    // add to linked-list
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    // find the last
    Node *last = pList->head;
    if (last) {
        while (last->next) {
            last = last->next;
        }
        // attach
        last->next = p;
    } else {
        pList->head = p;
    }
}

// 遍历
void print(List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next) {
        printf("%d\t", p->value);
    }
    printf("\n");
}

// 查找
void search(List *pList, int number)
{
    Node *p;
    int isFound = 0;
    for (p = pList->head; p; p = p->next) {
        if (p->value == number) {
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound) {
        printf("没找到\n");
    }
    return 0;
}

// 删除——双指针法
void delete (List *pList, int number)
{
    Node *q, *p;
    for (q = NULL, p = pList->head; p; q = p, p = p->next) {
        if (p->value == number) {
            if (q) {
                q->next = p->next;
            } else {
                pList->head = p->next;
            }
            free(p);
            break;
        }
    }
}

// 清除链表
void clear(List *pList)
{
    Node *q, *p;
    for (p = pList->head; p; p = q) {
        q = p->next;
        free(p);
    }
}