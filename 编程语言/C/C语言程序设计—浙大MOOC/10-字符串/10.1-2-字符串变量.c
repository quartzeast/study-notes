/*
    字符串常量：
        char* s = "Hello, world!";
        • s 是⼀个指针，初始化为指向⼀个字符串常量
            • 由于这个常量所在的地⽅，所以实际上s是 const char* s ，但是由于历史的原因，编译器接受不带 const的写法
            • 但是试图对s所指的字符串做写⼊会导致严重的后果
        • 如果需要修改字符串，应该⽤数组：
            char s[] = "Hello, world!";

    指针还是数组？
        • char *str = “Hello”;
        • char word[] = “Hello”;
        • 数组：这个字符串在这⾥
            • 作为本地变量空间⾃动被回收
        • 指针：这个字符串不知道在哪⾥
            • 处理参数
            • 动态分配空间
        • 如果要构造⼀个字符串—>数组
        • 如果要处理⼀个字符串—>指针

    char*是字符串？
        • 字符串可以表达为char*的形式
        • char*不⼀定是字符串
            • 本意是指向字符的指针，可能指向的是字符的数组（就像int*⼀样）
        • 只有它所指的字符数组有结尾的0，才能说它所指的是字符串
*/

#include <stdio.h>

int main(void)
{
    int i = 0;
    char *s = "Hello World"; // 字符串常量位于程序的代码段，且是只读的，不能进行写操作
    char *s2 = "Hello World";
    char s3[] = "Hello World";
    // s[0] = 'B';

    printf("&i=%p\n", &i);
    printf("s =%p\n", s);
    printf("s2=%p\n", s2);
    printf("s3=%p\n", s3);
    s3[0] = 'B';
    printf("Here!s3[0]=%c\n", s3[0]);
    return 0;
}
