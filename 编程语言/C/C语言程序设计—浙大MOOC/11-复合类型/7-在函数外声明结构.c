#include <stdio.h>

// 声明结构类型
struct date {
    int month;
    int day;
    int year;
};

int main()
{
    // 定义结构类型的变量
    struct date today;

    today.month = 07;
    today.day = 31;
    today.year = 2014;

    printf("Today's date is %d-%d-%d.\n", today.year, today.month, today.day);
    return 0;
}