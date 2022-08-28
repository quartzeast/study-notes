#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point *getStruct(struct point *p);
void output(struct point p);
void print(const struct point *p);

int main()
{
    struct point y = { 0, 0 };
    getStruct(&y);
    output(y);
    output(*getStruct(&y));

    print(getStruct(&y));

    getStruct(&y)->x = 0;
    *getStruct(&y) = (struct point) { 1, 2 };

    printf("5#函数 %d %d", y.x, y.y);

    return 0;
}

struct point *getStruct(struct point *p)
{
    scanf("%d", &p->x);
    scanf("%d", &p->y);
    printf("1#函数 %d, %d\n", p->x, p->y);
    return p;
}

void output(struct point p)
{
    printf("2#函数 %d,%d\n", p.x, p.y);
}

void print(const struct point *p)
{
    printf("3#函数 %d %d\n", p->x, p->y);
}