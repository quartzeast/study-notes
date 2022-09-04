#include <stdio.h>

void minmax(int *a, int len, int *min, int *max);

int main(void)

{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 16, 17, 21, 23, 55 };
    int min, max;
    printf("main sizeof(a)=%lu\n", sizeof(a));
    printf("main a=%p\n", a);
    minmax(a, sizeof(a) / sizeof(a[0]), &min, &max);
    printf("a[0]=%d\n", a[0]);
    printf("min=%d,max=%d\n", min, max);
    int *p = &min;
    printf("*p=%d\n", *p);
    printf("p[0]=%d\n", p[0]);
    printf("*a=%d\n", *a);
    int *q = a;
    return 0;
}

// void minmax(int a[], int len, int *min, int *max)
void minmax(int *a, int len, int *min, int *max)
{
    int i;
    printf("minmax sizeof(a)=%lu\n", sizeof(a));
    printf("minmax a=%p\n", a);
    a[0] = 1000;
    *min = *max = a[0]; //初始化赋值，不然min和max初始值等于0， 而数组中没有0则容易出错
    for (i = 1; i < len; i++) {
        if (*min > a[i]) {
            *min = a[i];
        }
        if (*max < a[i]) {
            *max = a[i];
        }
    }
}