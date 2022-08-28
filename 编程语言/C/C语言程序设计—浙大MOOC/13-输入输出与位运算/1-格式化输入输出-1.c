// printf
#include <stdio.h>

int main()
{
    printf("%9d\n", 123);
    printf("%-9d\n", 123);

    printf("%+9d\n", 123);
    printf("%+-9d\n", 123);

    printf("%+-9d\n", -123);

    printf("%09d\n", 123);
    printf("%-9d\n", -123);

    printf("%9.2f\n", 123.0);

    printf("%*d\n", 6, 123);
    printf("%6d\n", 123);
    int len = 6;
    printf("%*d\n", len, 123);

    printf("%d\n", 12345);
    printf("%hhd\n", 12345); //视具体编译器而定，报错并非一定！
    printf("%hhd\n", (char)12345);
    printf("%d\n", (char)12345);

    int num;

    //	printf("%hhd%n\n",(char)12345,&num);
    //	printf("%d\n",num);
    printf("%d%n\n", 12345, &num);
    printf("%d\n", num);

    return 0;
}