/*
    写一个程序，输入数量不确定的 [0, 9] 范围内的整数，统计每一种数字出现的次数，输入 -1 表示结束
*/
#include <stdio.h>

int main(void)
{
    const int number = 10; // 数组的大小，c99
    int x;
    int count[number]; // 定义数组
    int i;

    for (i = 0; i < number; i++) { // 初始化数组、或者使用 int count[number] = {0};
        count[i] = 0;
    }

    scanf("%d", &x);
    while (x != -1) {
        if (x >= 0 && x <= 9) {
            count[x]++; // 数组参与运算
        }
        scanf("%d", &x);
    }
    for (i = 0; i < 10; i++) { // 遍历数组输出
        printf("%d:%d\n", i, count[i]);
    }
    return 0;
}