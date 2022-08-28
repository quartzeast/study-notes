#include <stdio.h>

int f(void);
int gAll = 12;

int main()
{
    printf("in %s gAll = %d\n", __func__, gAll);
    f();
    printf("again in %s gAll = %d\n", __func__, gAll);
    return 0;
}

int f(void)
{
    int gAll = 1;
    {
        int gAll = 2;
        printf("in %s gAll = %d\n", __func__, gAll);
        gAll += 2;
        printf("again in %s gAll = %d\n", __func__, gAll);
    }
    printf("函数%d\n", gAll);

    return gAll;
}