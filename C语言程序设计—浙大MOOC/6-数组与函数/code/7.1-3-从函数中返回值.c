#include <stdio.h>

/*
    return 停止函数的执行，并返回一个值

    return;
    return expr;

    函数的返回值可以赋值给变量，可以再传递给函数

    没有返回值的函数：
        void 函数名(参数表)
        不能使用带值的 return
        可以没有 return
        调用的时候不能做返回值的赋值
    如果函数有返回值，则必须使用带值的 return
*/

int max(int a, int b)
{
    int ret;
    if (a > b)
        ret = a;
    else
        ret = b;
    return ret; /* 单一出口 */
}

int main(int argc, char const* argv[])
{
    int a, b, c;
    a = 5;
    b = 6;
    c = max(10, 12);
    c = max(a, b);
    c = max(c, 23);
    c = max(max(c, a), 5);
    printf("%d\n", max(a, b));
    return 0;
}
