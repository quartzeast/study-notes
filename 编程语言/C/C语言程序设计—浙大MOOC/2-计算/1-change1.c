#include <stdio.h>

int main()
{
    int price = 0; // 定义变量时的赋值，所以这时候的赋值叫做初始化

    // 定义变量时不一定要进行初始化，但在使用前至少需要进行一次赋值，否则该变量的值就是未定义的

    printf("请输入金额（元）：");
    scanf("%d", &price); // 如果输入的不是数字，将默认为 0

    // c99! c99 运行在程序的任何地方定义变量，只要它出现在变量的第一次使用前
    // ANSI C 只能在变量的开头定义变量
    int change = 100 - price;

    printf("找您%d元。\n", change);

    return 0;
}