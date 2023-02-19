#include<stdio.h>
//枚举类型
enum Sex
{
    //枚举的可能取值
    MALE=2,//0，从零开始,后面递增
    FEMALE=4,
    SECRET=4//没有赋值的话，就等于前一项加1,我居然可以赋值小于前一项的数字，或者相等的
};
enum Color
{
    RED=1,
    GREEN,
    BLUE
};
int main()
{
    // enum Sex s=MALE;
    // s=FEMALE;
    // s=SECRET;
    // enum Color c=BLUE;
    //enum Color c=2;//类型不同，实际上不符合语法标准
    printf("%d %d %d\n",RED,GREEN,BLUE);
    printf("%d %d %d\n",MALE,FEMALE,SECRET);
    return 0;
}