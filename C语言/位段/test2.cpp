#include<stdio.h>
struct S
{
	int a:3;
	int b:4;
	int c:5;
	int d:4;
};
//char->one byte->8bits
//(3,4),(5),(4)->3byte 
//10->1010,->010（从右到左分配bit）
//20->16+4=10100->0100
//先使用低位，然后开辟字节时拼到左边
int main(){
	struct S s={0};
	s.a=10;
	s.b=20;
	s.c=3;
	s.d=4;
	printf("%d\n",sizeof(s));
	return 0;
}
