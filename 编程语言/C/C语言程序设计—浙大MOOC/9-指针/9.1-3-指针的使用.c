/*
    指针应用场景一
        交换两个变量的值

        #include <stdio.h>

        void swap(int *pa, int *pb);

        int main(void)
        {
            int a = 5;
            int b = 6;
            swap(&a, &b);
            printf("a=%d, b=%d\n", a, b);

            return 0;
        }

        void swap(int *pa, int *pb)
        {
            int t = *pa;
            *pa = *pb;
            *pb = t;
        }

    指针应用场景二
        函数返回多个值，某些值只能通过指针返回
            传入的参数实际上是需要保存带回的结果的变量

            #include <stdio.h>

            void minmax(int a[], int len, int *max, int *min);

            int main(void)
            {
                int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 16, 17, 21, 23, 55 };
                int min, max;
                minmax(a, sizeof(a) / sizeof(a[0]), &min, &max);
                printf("min=%d,max=%d\n", min, max);

                return 0;
            }

            void minmax(int a[], int len, int *min, int *max)
            {
                int i;
                *min = *max = a[0];
                for (i = 1; i < len; i++) {
                    if (a[i] < *min) {
                        *min = a[i];
                    }
                    if (a[i] > *max) {
                        *max = a[i];
                    }
                }
            }

    指针应用场景二b
        函数返回运算的状态，结果通过指针返回
        常用的套路是让函数返回特殊的不属于有效范围内的值来表示出错：
            -1或0（在文件操作会看到大量的例子）
        但是当任何数值都是有效的可能结果时，就得分开返回了
            后续的语⾔（C++,Java）采⽤了异常机制来解决这 个问题

    指针最常⻅见的错误
        定义了指针变量，还没有指向任何变量，就开始使⽤指针
*/

#include <stdio.h>

/**
 * @return 如果除法成功，返回1，否则返回0
 */
int divide(int a, int b, int *result);

int main(void)
{
    int a = 5;
    int b = 2;
    int c;
    if (divide(a, b, &c)) {
        printf("%d/%d=%d\n", a, b, c);
    }
    return 0;
}

int divide(int a, int b, int *result)
{
    int ret = 1;
    if (b == 0)
        ret = 0;
    else
        *result = a / b;
    return ret;
}