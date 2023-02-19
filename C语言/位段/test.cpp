#include<stdio.h>
//位段：二进制位
struct S
{
    int _a:2;//两个bit位
    int _b:5;
    int _c:10;
    int _d:30;
};
//47bit->6个字节,因为一个字节等于八个比特
//由于开辟内存的方式是按照整型的方式来开辟的，也就是4个字节4个字节的开辟，所以最后内存大小就是8个字节
//位段后面的数字不能大于32
int main()
{
    struct S s;
    printf("%d\n",(int)sizeof(s));//8个字节
    return 0;
}
