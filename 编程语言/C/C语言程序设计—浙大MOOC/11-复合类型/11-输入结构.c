#include <stdio.h>

struct point {
    int x;
    int y;
};

// void getStruct(struct point *P);
struct point getStruct(void);
void output(struct point p);

int main()
{
    struct point y = { 0, 0 };
    // getStruct(&y);
    y = getStruct();
    output(y);

    return 0;
}

// void getStruct(struct point *p)
// {
//     scanf("%d", &(*p).x);
//     scanf("%d", &(*p).y);
//     printf("1#函数 %d, %d\n", p->x, p->y);
// }

struct point getStruct(void)
{
    struct point p;
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    printf("1#函数 %d,%d\n", p.x, p.y);
    return p;
}

void output(struct point p)
{
    printf("2#函数 %d, %d\n", p.x, p.y);
}