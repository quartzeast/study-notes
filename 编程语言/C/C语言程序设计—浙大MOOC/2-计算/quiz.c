#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    num = num % 10 * 100 + num / 10 % 10 * 10 + num / 100;
    printf("%d", num);

    return 0;
}