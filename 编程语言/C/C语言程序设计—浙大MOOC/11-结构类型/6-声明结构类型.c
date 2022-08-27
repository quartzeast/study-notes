// 结构类型
#include <stdio.h>

struct point {
    int x;
    int y;
};

struct {
    int x;
    int y;
} p1, p2;

struct point {
    int x;
    int y;
} p1, p2;

int main()
{
    // 一个结构就是一个复合的数据类型
    // 其中可以有多个各种类型的成员
    struct date {  // 声明结构类型 date
        int month; // 成员变量
        int day;
        int year;
    };

    struct date today;

    today.month = 07;
    today.day = 31;
    today.year = 2014;

    printf("Today's date is %d-%d-%d.\n",
        today.year, today.month, today.year);
    return 0;
}