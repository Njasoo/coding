#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

const int N=2e5+5;
int n, sum[N][26];
ll m;
string s;
ll a[N];

bool check(int l, int r, int c) {
    for(int j=0; j<26; j++) {
        if(j!=c) {
            int cnt=sum[r][j]-sum[l-1][j];
            if(cnt)
                return 1;
        }
    }
    return 0;
}

int find(int l, int r, int c) {
    int lo=l, hi=r;
    if(sum[r][c]-sum[l-1][c]==r-l+1)
        return 0;
    while(lo<hi) {
        int mid=(lo+hi)/2;
        if(check(lo, mid, c)) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    return hi;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    s=' '+s;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<26; j++) {
            sum[i][j]=sum[i-1][j];
        }
        sum[i][s[i]-'a']++;
    }
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n;) {
        int j=i+1;
        while(j<=n && s[j]==s[i]) {
            j++;
        }
        sort(a+i, a+j);
        i=j;
    }
    vector<int> pos;
    for(int i=1; i<n; i++) {
        int p=find(i+1, n, s[i]-'a');
        if(!p)
            continue;
        if(s[p]>s[i] && m-a[i]>=0) {
            m-=a[i];
            pos.push_back(i);
        }
    }
    for(int i=1; i<=n; i++) {
        cout << s[i];
        if(binary_search(pos.begin(), pos.end(), i)) {
            cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}