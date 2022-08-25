/*
    使用 putchar 和 getchar

        putchar
            • int putchar(int c);
            • 向标准输出写⼀个字符
            • 返回写了⼏个字符，EOF（-1）表⽰写失败

        getchar
            • int getchar(void);
            • 从标准输⼊读⼊⼀个字符
            • 返回类型是int是为了返回EOF（-1）
            • Windows—>Ctrl-Z
            • Unix—>Ctrl-D

        标准库中的字符串函数
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ch;

    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
    printf("EOF\n");
    return 0;
}
