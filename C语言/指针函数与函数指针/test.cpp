#include<stdio.h>
#include<stdlib.h>

int c;
int* add(int x,int y)
{
    c=x+y;
    return &c;
}

int* sub(int x,int y)
{
    c=x-y;
    return &c;
}

// int (*f)(int x,int y);
int* (*f)(int x,int y);

int main(int argc,char *argv[])
{
    f=add;//不加取址符也行，函数名类似数组名，本身就是指向函数的一个指针，但是为什么取址也可以，我不知道
    // printf("1+2=%d\n",(*f)(1,2));
    printf("1+2=%d\n",*(*f)(1,2));
    f=&sub;
    // printf("1-2=%d\n",(*f)(1,2));
    printf("1-2=%d\n",*(*f)(1,2));
    return 0;
}