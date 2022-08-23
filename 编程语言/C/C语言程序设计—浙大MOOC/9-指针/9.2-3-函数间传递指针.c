/*
    好的模式
        • 如果程序中要⽤到动态分配的内存，并且会在函数之间传递，不要让函数申请内存后返回给调用者
        • 因为⼗有⼋九调⽤者会忘了free，或找不到合适的时机来free
        • 好的模式是让调⽤者⾃⼰申请，传地址进函数，函数再返回这个地址出来

    函数返回指针？
        • 返回指针没问题，关键是谁的地址？
        • 本地变量（包括参数）？函数离开后这些变量就不存在了，指针所指的是不能⽤的内存
        • 传⼊的指针？没问题
        • 动态申请的内存？没问题
        • 全局变量—>以后再解释

    函数返回数组？
        • 如果⼀个函数的返回类型是数组，那么它实际返回的也是数组的地址
        • 如果这个数组是这个函数的本地变量，那么回到调⽤函数那⾥，这个数组就不存在了
        • 所以只能返回（和返回指针是一样的！）
            • 传⼊的参数：实际就是在调⽤者那⾥
            • 全局变量或动态分配的内存
*/
#include <stdio.h>

int *init(int a[], int length);
int *print(int a[], int length);

// 除非函数的作用就是分配空间，否则不要在函数中malloc然后传出去用
int main()
{
    const int MAX_SIZE = 1000;
    int size;
    do {
        printf("输入数量 (0, 1000)：");
        scanf("%d", &size);
    } while (size > 0 && size < MAX_SIZE);

    int *a = (int *)malloc(size * sizeof(int)); // 在同一个地方 malloc 和 free
    print(init(a, size), size);
    free(a);

    return 0;
}

int *init(int a[], int length)
{
    int i;
    for (i = 0; i < length; i++) {
        a[i] = i;
    }
    return a;
}

int *print(int a[], int length)
{
    int i;
    for (i = 0; i < length; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return a;
}