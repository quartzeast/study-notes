#include <stdio.h>

int main(void)
{
    int i = 0;
    int p;
    p = (int)&i; // 将地址值进行强制类型转换为 int
    // p = (int)&(i+p); // 不能取地址
    // p = (int)&(i++);
    // p = (int)&(++i);
    printf("0x%x\n", p); // 32 位架构编译和 64 位架构编译结果不同，会发生溢出
    printf("%p\n", &i);
    printf("%lu\n", sizeof(int)); // 4
    printf("%lu\n", sizeof(&i));  // 8
    printf("\n");

    printf("%p\n", &i);
    printf("%p\n", &p);
    printf("\n");

    int a[10];

    // &a == a == &a[0]
    printf("%p\n", &a) ;
    printf("%p\n", a);
    printf("%p\n", &a[0]);
    printf("%p\n", &a[1]);
    printf("\n");

    return 0;
}
