#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<endl
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    cout<<n/5+(n%5!=0)<<'\n';   
    return 0;
}