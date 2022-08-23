/*
    什么是函数？
        • 函数是一块代码，接收零个或多个参数，做一件事情，并返回零个或一个值
        • 可以先想像成数学中的函数：
            • y = f(x)

    函数定义
        void sum(int begin, int end)
        {
            int i;
            int sum = 0;
            for (i = begin; i <= end; i++) {
                sum += i;
            }
            printf("%d到%d的和为%d\n", begin, end, sum)
        }
        函数头
            返回类型、函数名、参数表
        函数体

    调用函数
        • 函数名(参数值);
        • ( )起到了表⽰函数调⽤的重要作⽤
            • 即使没有参数也需要()
        • 如果有参数，则需要给出正确的数量和顺序
        • 这些值会被按照顺序依次⽤来初始化函数中的参数
            sum(1, 10);
            sum(20, 30);
            sum(35, 45);
*/
