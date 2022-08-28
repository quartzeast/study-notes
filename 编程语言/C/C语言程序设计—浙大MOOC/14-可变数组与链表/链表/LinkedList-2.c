#include "node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _list {
    Node *head;
} List;

void add(List *pList, int number);

int main(int argc, char const *argv[])
{
    List list;
    int number;
    list.head = NULL;
    do {
        scanf("%d", &number);
        if (number != -1) {
            add(&list, number);
        }
    } while (number != -1);
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