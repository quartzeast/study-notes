/*
    字符串运算
        字符串赋值？
            • char *t = “title”;
            • char *s;
            • s = t;
            • 并没有产⽣新的字符串，只是让指针s指向了t所指的字符串，对s的任何操作就是对t做的

        字符串输⼊输出
            • char string[8];
            • scanf(“%s”, string);
            • printf(“%s”, string);

            • scanf读⼊⼀个单词（到空格、tab或回⻋车为⽌）
            • scanf是不安全的，因为不知道要读⼊的内容的⻓长度

        安全的输⼊
            • char string[8];
            • scanf(“%7s”, string);
            • 在%和s之间的数字表⽰最多允许读⼊的字符的数量，这个数字应该⽐数组的⼤⼩⼩⼀
                • 下⼀次scanf从哪⾥开始？

        常⻅见错误
            • char *string;
            • scanf(“%s”, string);
            • 以为char*是字符串类型，定义了⼀个字符串类型的变量string就可以直接使⽤了
                • 由于没有对string初始化为0，所以不⼀定每次运⾏都出错

        空字符串
            • char buffer[100]=””;
                • 这是⼀个空的字符串，buffer[0] == '\0'
            • char buffer[] = "";
                • 这个数组的⻓长度只有1！
*/
#include <stdio.h>

void f(void)
{
    char word[8];
    char word2[8];
    scanf("%7s", word);
    scanf("%7s", word2);
    printf("%s##%s##\n", word, word2);
}

int main(void)
{
    f();
    return 0;
}