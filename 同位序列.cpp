#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vt vector
#define fi first
#define se second
#define pb push_back
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

int get(int x) {
    int pos0=-1;
    bool flag1=0;
    for (int i=0; i<31; i++) {
        if (x>>i&1) {
            flag1=1;
        } else {
            if (flag1) {
                pos0=i;
                break;
            }
        }
    }
    int pos1=pos0-1;
    x-=1<<pos1;
    x+=1<<pos0;
    int low1=-1;
    for (int i=0; i<pos1; i++) {
        if (x>>i&1) {
            low1=i;
            break;
        }
    }
    if (low1!=-1) {
        int tmp1=INT_MAX;
        tmp1>>=pos1;
        tmp1<<=pos1;
        int tmp2=(1<<pos1)-1;
        int t1=x&tmp1;
        int t2=x&tmp2;
        t2>>=low1;
        x=t1|t2;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vt<int> a(n);
    unordered_set<int> S;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        S.insert(a[i]);
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    reverse(all(a));
    map<int, int> dp;
    int mx=0;
    for (int i=0; i<n; i++) {
        int nex=get(a[i]);
        // db(a[i]), db(nex), el;
        if (S.count(nex)) {
            dp[a[i]]=dp[nex]+1;
        } else {
            dp[a[i]]=1;
        }
        mx=max(mx, dp[a[i]]);
    }
    vt<int> ans;
    for (int i=n-1; i>=0; i--) {
        if (dp[a[i]]==mx) {
            int now=a[i];
            while (S.count(now)) {
                ans.pb(now);
                now=get(now);
            }
            break;
        }
    }
    cout << mx << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}