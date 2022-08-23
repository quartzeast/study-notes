/*
    其他细节
        没有参数时
            • void f(void);
            • 还是
            • void f();
                • 在传统C中，它表⽰f函数的参数表未知，并不表⽰没有参数

        逗号运算符
            • 调用函数时的逗号和逗号运算符怎么区分？
            • 调用函数时的圆括号里的逗号是标点符号，不是运算符
                • f(a, b)
                • f((a,b)) 先做()里的运算，为逗号运算符
    
    函数里的函数
        c语言不允许函数嵌套定义
    
    这是什么？
        int i, j, sum(int a, int b); // 定义 i, j，和 sum 的原型声明
        return (i); // () 没有任何意义，加上括号也是一个表达式，不要这么写
    
    关于 main:
        • int main() 也是一个函数
        • 要不要写成 int main(void) ？
            • 编译没有问题，main 是 C 语言程序的入口，但不是程序中运行的第一行代码
        • return 的 0 有人看吗？
            • Windows: if error level 1...
            • Unix Bash: echo $?
            • Csh: echo $status
*/

#include <stdio.h>

// 原型中一定要将参数（类型）写全，如果确定没有参数，则要显示的声明 void
void swap();

int main()
{
    int a = 5;
    int b = 6;
    swap(a, b);

    {
        int a = 0;
        // int a = 10;
        printf("a=%d\n", a);
    }

    printf("a=%d,b=%d\n", a, b);
    return 0;
}

void swap(double a, double b)
{
    int t = a;
    a = b;
    b = t;
}
