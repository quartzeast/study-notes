#include <stdio.h>

typedef union {
    int i;
    char ch[sizeof(int)];
} CHI;

int main()
{
    CHI chi;
    chi.i = 1234;

    int i;
    for (i = 0; i < sizeof(int); i++) {
        printf("%02hhX ", chi.ch[i]);
    }
    printf("\n");
    return 0;
}
