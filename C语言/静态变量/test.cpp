#include<iostream>

using namespace std;

void click()
{
    static int num=0;//只会被初始化一次
    num+=1;
    cout<<"此时的点击量是："<<num<<endl;
}

int main()
{
    for(int i=0;i<5;i++)
    {
        click();
    }
    return 0;
}
