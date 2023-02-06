#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        for(int a=1;a<=m;a++)
        {
            cout<<a<<endl;
        }
    }
    else if(n==2)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                cout<<a<<" "<<b<<endl;
            }
        }
    }
    else if(n==3)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                for(int c=b+1;c<=m;c++)
                {
                    cout<<a<<" "<<b<<" "<<c<<endl;
                }
            }
        }
    }
    else if(n==4)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                for(int c=b+1;c<=m;c++)
                {
                    for(int d=c+1;d<=m;d++)
                    {
                        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                    }
                }
            }
        }
    }
    else if(n==5)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                for(int c=b+1;c<=m;c++)
                {
                    for(int d=c+1;d<=m;d++)
                    {
                        for(int e=d+1;e<=m;e++)
                        {
                            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
                        }
                    }
                }
            }
        }
    }
    else if(n==6)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                for(int c=b+1;c<=m;c++)
                {
                    for(int d=c+1;d<=m;d++)
                    {
                        for(int e=d+1;e<=m;e++)
                        {
                            for(int f=e+1;f<=m;f++)
                            {
                                cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==7)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                for(int c=b+1;c<=m;c++)
                {
                    for(int d=c+1;d<=m;d++)
                    {
                        for(int e=d+1;e<=m;e++)
                        {
                            for(int f=e+1;f<=m;f++)
                            {
                                for(int g=f+1;g<=m;g++)
                                {
                                    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==8)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                for(int c=b+1;c<=m;c++)
                {
                    for(int d=c+1;d<=m;d++)
                    {
                        for(int e=d+1;e<=m;e++)
                        {
                            for(int f=e+1;f<=m;f++)
                            {
                                for(int g=f+1;g<=m;g++)
                                {
                                    for(int h=g+1;h<=m;h++)
                                    {
                                        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==9)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                for(int c=b+1;c<=m;c++)
                {
                    for(int d=c+1;d<=m;d++)
                    {
                        for(int e=d+1;e<=m;e++)
                        {
                            for(int f=e+1;f<=m;f++)
                            {
                                for(int g=f+1;g<=m;g++)
                                {
                                    for(int h=g+1;h<=m;h++)
                                    {
                                        for(int i=h+1;i<=m;i++)
                                        {
                                            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==10)
    {
        for(int a=1;a<=m;a++)
        {
            for(int b=a+1;b<=m;b++)
            {
                for(int c=b+1;c<=m;c++)
                {
                    for(int d=c+1;d<=m;d++)
                    {
                        for(int e=d+1;e<=m;e++)
                        {
                            for(int f=e+1;f<=m;f++)
                            {
                                for(int g=f+1;g<=m;g++)
                                {
                                    for(int h=g+1;h<=m;h++)
                                    {
                                        for(int i=h+1;i<=m;i++)
                                        {
                                            for(int j=i+1;j<=m;j++)
                                            {
                                                cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<" "<<j<<endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}