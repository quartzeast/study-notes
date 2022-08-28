/*
    & 运算符取得变量的地址

    运算符 &
        scanf("%d", &i); 里的 &
        或的变量的地址，它的操作数必须是变量
            int i;
            printf("%x", &i);
        地址的大小是否与 int 相同取决于编译器
            int i;
            printf("%p", &i);
        & 不能取的地址
            & 不能对没有地址的东西取地址
                &(a+b), &(a++), &(++a)
        试试这些 &
            变量的地址
            相邻的变量的地址
                int i = 0;
                int p;
                printf("%p\n", &i);
                print("%p\n", &p);
            & 的结果的 sizeof
            数组的地址

            数组单元的地址
            相邻的数组单元的地址
*/

#include <stdio.h>

int main(void)
{
    int i = 0;
    int p;
    p = (int)&i;
    // p = (int)&(i+p);
    // p = (int)&(i++);
    // p = (int)&(++i);
    printf("0x%x\n", i);
    printf("%p\n", &i);
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(&i));
    printf("\n");

    printf("%p\n", &i);
    printf("%p\n", &p);
    printf("\n");

    int a[10];

    printf("%p\n", &a);
    printf("%p\n", a);
    printf("%p\n", &a[0]);
    printf("%p\n", &a[1]);
    printf("\n");

    return 0;
}
