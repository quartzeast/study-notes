/*
    字符串数组
        • char **a
            • a是⼀个指针，指向另⼀个指针，那个指针指向⼀个字符（串）
        • char a[][]
            • a是⼀个⼆维数组，第⼆个维度的⼤⼩不知道，不能编译
        • char a[][10]
            • a是⼀个⼆维数组，a[x]是⼀个char[10]
        • char *a[]
            • a是⼀个⼀维数组，a[x]是⼀个char*

    程序参数
        • int main(int argc, char const *argv[])
        • argv[0]是命令本⾝
        • 当使⽤Unix的符号链接时，反映符号链接的名字
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < argc; i++) {
        printf("%d:%s\n", i, argv[i]);
    }

    return 0;
}