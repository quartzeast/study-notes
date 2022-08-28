// printf 和 scanf 的返回值
#include <stdio.h>

int main()
{
    int num;
    int i1 = scanf("%d", &num);
    int i2 = printf("%d\n", num);
    printf("%d:%d\n", i1, i2);
    return 0;
}