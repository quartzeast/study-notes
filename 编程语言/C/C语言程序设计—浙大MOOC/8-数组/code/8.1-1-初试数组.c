#include <stdio.h>

int main()
{
    int x;
    double sum = 0;
    int cnt = 0;
    int numbers[100]; // 定义数组
    scanf("%d", &x);
    while (x != -1) {
        // 对数组中的元素赋值，这个程序是危险的，因为输入的数据可能超过 100 个
        numbers[cnt] = x;

        {
            int i;
            printf("%d\t", cnt);
            for (i = 0; i <= cnt; i++) {
                printf("%d\t", numbers[i]);
            }
            printf("\n");
        }

        sum += x;
        cnt++;
        scanf("%d", &x);
    }
    if (cnt > 0) {
        int i;
        double average = sum / cnt;
        printf("%f\n", sum / cnt);
        for (i = 0; i < cnt; i++) { // 遍历数组
            if (numbers[i] > average) { // 使用数组
                printf("%d\n", numbers[i]);
            }
        }
        return 0;
    }
}