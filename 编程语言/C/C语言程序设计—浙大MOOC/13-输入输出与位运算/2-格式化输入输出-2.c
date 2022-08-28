// scanf
#include <stdio.h>

int main()
{
    int num;
    scanf("%*d%d", &num);
    printf("%d\n", num);

    scanf("%i", &num);
    printf("%d\n", num);

    //	int a,b;
    //	scanf("%d %d",&a,&b);
    //	printf("%d %d\n",a,b);
    return 0;
}