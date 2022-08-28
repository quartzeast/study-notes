#include "max.h"
#include "min.h"
#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 6;
    printf("%d\n", max(a, gAll));
    return 0;
}

// gcc main.c max.c
// gcc --save-temps main.c -c
// tail -n 50 main.i
// .i 文件中 # 开头为注释