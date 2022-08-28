/*
    输⼊数据
        • 如果输⼊数据时，先告诉你个数，然后再输⼊，要记录每个数据
        • C99可以⽤变量做数组定义的⼤⼩，C99之前呢？
        • int *a = (int*)malloc(n*sizeof(int));

    malloc
        #include <stdlib.h>
        void* malloc(size_t size);
        • 向malloc申请的空间的⼤⼩是以字节为单位的
        • 返回的结果是void*，需要类型转换为⾃⼰ 需要的类型
            • (int*)malloc(n*sizeof(int))

    没空间了？
        • 如果申请失败则返回0，或者叫做NULL
        • 你的系统能给你多⼤的空间？

    free()
        • 把申请得来的空间还给“系统”
        • 申请过的空间，最终都应该要还
        • 只能还申请来的空间的⾸地址
            void *p;
            int cnt = 0;
            p = malloc(100 * 1024 * 1024);
            p++;
            free(p);

            int i;
            void *p;
            p = &i;
            free(p);
            pointer being freed was not allocated.

        • free(0)/free(NULL)
            void *p = 0; // 写指针的好习惯
            free(p);

    常⻅问题
        • 申请了没free—>⻓长时间运⾏内存逐渐下降
            • 新⼿：忘了
            • ⽼⼿：找不到合适的free的时机
        • free过了再free
        • 地址变过了，直接去free
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;
    int *a;
    int i;
    printf("输入数量：");
    scanf("%d", &number);
    // int a[number] c99
    a = (int *)malloc(number * sizeof(int));
    for (i = 0; i < number; i++) {
        scanf("%d", &a[i]);
    }

    for (i = number - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    free(a);

    void *p;
    int cnt = 0;
    while ((p = malloc(100 * 1024 * 1024))) {
        cnt++;
    }
    printf("分配了%d00MB的空间\n", cnt);
    return 0;
}