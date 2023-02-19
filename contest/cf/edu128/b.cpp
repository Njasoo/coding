#include <bits/stdc++.h>
using namespace std;
char f[10005][10005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        int minx=9999,miny=9999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>f[i][j];
                if(f[i][j]=='R')
                {
                    minx=min(minx,i);
                    miny=min(miny,j);
                }
            }
        }
        if(f[minx][miny]=='R')cout<<"YES\n";
        else cout<<"NO\n";
    }   
    return 0;
}