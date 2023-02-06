#include <bits/stdc++.h>

using namespace std;

const int LOG = 18;
int a[100005][LOG];
int n, m;

void build() {
    for (int i = 1; i <= n; i++) {
        st[i][0] = b[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return max(a[l][k], a[r - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
    }
    for(int j=1;j<LOG;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            a[i][j]=max(a[i][j-1],a[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<'\n';
    }
    return 0;
}