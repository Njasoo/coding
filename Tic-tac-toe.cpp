#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MOD=998244353;
char f[105][105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cntx=0,cnto=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>f[i][j];
            if(f[i][j]=='X')cntx++;
            if(f[i][j]=='0')cnto++;
        }
    }   
    if(cntx==0&&cnto==0)
    {
        cout<<"first\n";
        return 0;
    }
    int winx=0,wino=0;
    if(cnto>cntx||cntx-cnto>1)
    {
        cout<<"illegal\n";
    }
    else
    {
        if(f[1][1]==f[2][2]&&f[2][2]==f[3][3])
        {
            if(f[1][1]=='X')winx=1;
            if(f[1][1]=='0')wino=1;
        }
        if(f[1][3]==f[2][2]&&f[2][2]==f[3][1])
        {
            if(f[1][3]=='X')winx=1;
            if(f[1][3]=='0')wino=1;
        }
        if(f[1][1]==f[1][2]&&f[1][2]==f[1][3])
        {
            if(f[1][1]=='X')winx=1;
            if(f[1][1]=='0')wino=1;
        }
        if(f[2][1]==f[2][2]&&f[2][2]==f[2][3])
        {
            if(f[2][1]=='X')winx=1;
            if(f[2][1]=='0')wino=1;
        }
        if(f[3][1]==f[3][2]&&f[3][2]==f[3][3])
        {
            if(f[3][1]=='X')winx=1;
            if(f[3][1]=='0')wino=1;
        }
        if(f[1][1]==f[2][1]&&f[2][1]==f[3][1])
        {
            if(f[1][1]=='X')winx=1;
            if(f[1][1]=='0')wino=1;
        }
        if(f[1][2]==f[2][2]&&f[2][2]==f[3][2])
        {
            if(f[1][2]=='X')winx=1;
            if(f[1][2]=='0')wino=1;
        }
        if(f[1][3]==f[2][3]&&f[2][3]==f[3][3])
        {
            if(f[1][3]=='X')winx=1;
            if(f[1][3]=='0')wino=1;
        }
        if(winx&&wino)
        {
            cout<<"illegal\n";
        }
        else if(winx&&!wino)
        {
            if(cntx==cnto+1)cout<<"the first player won\n";
            else cout<<"illegal\n";
        }
        else if(wino&&!winx)
        {
            if(cnto==cntx)cout<<"the second player won\n";
            else cout<<"illegal\n";
        }
        else
        {
            if(cnto+cntx==9)cout<<"draw\n";
            else if(cnto==cntx)cout<<"first\n";
            else cout<<"second\n";
        }
    }
    return 0;
}