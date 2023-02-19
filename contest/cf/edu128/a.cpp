#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int L=max(l1,l2);
        int R=min(r1,r2);
        if(L<=R)cout<<L<<'\n';
        else cout<<l1+l2<<'\n';
    }   
    return 0;
}