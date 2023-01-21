n#include<stdio.h>
int main()
{
    int bits[105]={0};
    int n,index=0;
    scanf("%d",&n);
    while(n)
    {
        bits[index++]=n%2;
        n/=2;
    }
    while(index<8)
    {
        index++;
    }
    for(int i=0,j=index-1;i<j;i++,j--)
    {
        int t=bits[i];
        bits[i]=bits[j];
        bits[j]=t;
    }
    for(int i=0;i<index;i++)
    {
        if(bits[7-i])
        {
            printf("the function %d is called!\n",i);
        }
    }
    return 0;
}