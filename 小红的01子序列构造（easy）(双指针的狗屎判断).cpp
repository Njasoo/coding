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

const int MN=2e5;
int pref1[MN+5];
bool mark[MN+5];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s=' '+s;
    for (int i=1; i<=n; i++) {
        pref1[i]=pref1[i-1]+(s[i]=='1');
    }
    int i=1, j=1;
    ll cnt0=0;
    ll cur=0;
    pair<int, int> ans={0, 0};
    while (i<=n) {
        while (j<=n && cur<k) {
            if (s[j]=='1' && !mark[j]) {
                cur+=cnt0;
            }
            if (s[j]=='0' && !mark[j]) {
                // db(j), el;
                cnt0++;
            }
            mark[j]=1;
            // db(i), db(j), db(cur), el;
            if (cur>=k)
                break;
            j++;
        }
        if (cur==k) {
            ans={i, j};
            break;
        }
        if (j==n+1) {
            break;
        }
        if (s[i]=='0') {
            cnt0--;
            cur-=pref1[j]-pref1[i];
            // if (i==1) {
            //     db(cur), el;
            // }
        }
        i++;
    }
    if (ans.fi) {
        cout << ans.fi << " " << ans.se << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}