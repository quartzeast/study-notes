/*
    函数原型

        函数先后关系
            void sum(int begin, int end) // 函数的定义
            {
                ...
            }
            int main() {
                sum (1, 10);
                ...
                return 0;
            }
            • 像这样把sum()写在上⾯，是因为
            • C的编译器⾃上⽽下顺序分析你的代码
            • 也就是sum()要⼏个参数，每个参数的类型如何，返回什么类型
            • 这样它才能检查你对sum()的调⽤是否正确

        如果不知道
            • 也就是把要调⽤的函数放到下⾯了
            • 旧标准会假设你所调⽤的函数所有的参数都是int，返回也是int
            • 如果恰好不对...
                int a, b, c;
                a = 5;
                b = 6;
                c = max(10, 12);
                printf("%d\n", c);
                max(12, 13);
                return 0

                double max(double a, double b)
                {
                : error: conflicting types for 'max' double max(double, double b)

        函数原型
            • 函数头，以分号 ; 结尾，就构成了函数的原型
            • 函数原型的目的是告诉编译器这个函数⻓什么样
                • 名称
                • 参数（数量及类型）
                • 返回类型
            • 旧标准习惯把函数原型写在调⽤它的函数⾥⾯
            • 现在⼀般写在调⽤它的函数前⾯
            • 原型⾥可以不写参数的名字，但是⼀般仍然写上
 */

#include <stdio.h>

void sum(int begin, int end); // 函数原型声明

int main()
{
    sum(1, 10); // int sum(int, int) 根据原型判断
    sum(20, 30);
    sum(35, 45);
    return 0;
}

void sum(int begin, int end) // 函数定义
{
    int i;
    int sum = 0;
    for (i = begin; i <= end; i++) {
        sum += i;
    }
    printf("%d到%d的和是%d\n", begin, end, sum);
}