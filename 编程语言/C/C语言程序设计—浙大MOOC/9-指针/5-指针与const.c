/*
    指针与 const：指针本身和所指的变量都可能 const
        指针 -- 可以是const
        值 -- 可以是const

    指针是 const
        • 表⽰⼀旦得到了某个变量的地址，不能再指向其他变量
            • int * const q = &i; // q 是 const
            • *q = 26; // OK
            • q++; // ERROR

    所指是 const
        • 表⽰不能通过这个指针去修改那个变量（并不能使得那个变量成为 const）
            • const int *p = &i;
            • *p = 26; // ERROR! (*p) 是 const
            • i = 26; //OK
            • p = &j; //OK

    这些是啥意思？
        int i;
        const int* p1 = &i;
        int const* p2 = &i;
        int *const p3 = &i;

        判断哪个被const了的标志是const在*的前⾯还是后⾯

    转换
        • 总是可以把⼀个⾮const的值转换成const的
            void f(const int* x);
            int a = 15;
            f(&a); // ok
            const int b = a;

            f(&b); // ok
            b = a + 1; // Error!

        • 当要传递的参数的类型⽐地址⼤的时候，这是常⽤的⼿段：既能⽤⽐较少的字节数传递值给参数，⼜能避免函数对外⾯的变量的修改

    const数组
        • const int a[] = {1,2,3,4,5,6,};
        • 数组变量已经是const的指针了，这⾥的 const 表明数组的每个单元都是 const int
            • 所以必须通过初始化进⾏赋值

    保护数组值
        • 因为把数组传⼊函数时传递的是地址，所以那个函数 内部可以修改数组的值
        • 为了保护数组不被函数破坏，可以设置参数为const
            • int sum(const int a[], int length);
*/