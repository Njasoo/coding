#include<stdio.h>
union Un
{
    char c;
    int i;
};
int main()
{
    union Un u;
    printf("%d\n",sizeof(u));//4

    //下面三段代码的结果一样
    int a=
    printf("%p\n",&u);
    printf("%p\n",&(u.c));
    printf("%p\n",&(u.i));
    return 0;
}