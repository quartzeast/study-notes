/*
    素数求和
        「代码复制」是程序质量不良的表现
 */
#include <stdio.h>

/* 判断素数 */
int isPrime(int i)
{
    int ret = 1;
    int k;
    for (k = 2; k < i - 1; k++) {
        if (i % k == 0) {
            ret = 0;
            break;
        }
    }
    return ret;
}

/* 求和函数 */
void sum(int begin, int end)
{
    int i;
    int sum = 0;
    for (i = begin; i <= end; i++) {
        sum += i;
    }
    printf("%d到%d的和是%d\n", begin, end, sum);
}

int main()
{
    int m, n;
    int sum = 0;
    int cnt = 0;
    int i;

    scanf("%d %d", &m, &n);
    if (m == 1)
        m = 2;
    for (i = m; i <= n; i++) {
        if (isPrime(i)) {
            sum += i;
            cnt++;
        }
    }
    printf("%d %d\n", cnt, sum);

    return 0;
}
