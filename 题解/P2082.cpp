#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 1e5 + 5;
pair<long long, long long> t[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t + 1, t + 1 + n);
    long long ans = 0;
    // 这道就力扣上面的合并区间吧
    for (int i = 1; i <= n;) {
        int j = i;
        long long cnt = 0;
        long long curr = t[i].second;
        while (j <= n && t[j].first <= curr) {
            curr = max(curr, t[j].second);
            j++;
        }
        ans += curr - t[i].first + 1;
        i = j;
    }
    cout << ans << '\n';
    return 0;
}