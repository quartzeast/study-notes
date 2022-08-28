#include <stdio.h>

const int red = 0;
const int yellow = 1;
const int green = 2;

int main()
{
    int color = -1;
    char *colorName = NULL;

    printf("输入你喜欢的颜色的代码：");
    scanf("%d", &color);

    switch (color) {
    case red:
        colorName = "red";
        break;
    case yellow:
        colorName = "yellow";
        break;
    case green:
        colorName = "green";
        break;
    default:
        colorName = "unknown";
        break;
    }

    printf("你喜欢的颜色是 %s\n", colorName);
    return 0;
}