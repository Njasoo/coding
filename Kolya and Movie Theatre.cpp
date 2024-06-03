#include<bits/stdc++.h>
using namespace std;

long long n, m, d;

void solve() {
    cin >> n >> m >> d;
    priority_queue<int, vector<int>, greater<int>> q;
    long long sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        if (a > 0) {
            if ((int)q.size() == m) {
                if (a <= q.top()) continue;
                sum += a;
                sum -= q.top();
                q.push(a);
                q.pop();
//                if (sum - d * i > ans) {
//                    cerr << "i: " << i << endl;
//                }
                ans = max(ans, sum - d * i);
            } else {
                sum += a;
                q.push(a);
//                if (sum - d * i > ans) {
//                    cerr << "i: " << i << endl;
//                }
                ans = max(ans, sum - d * i);
            }
        }
    }
    cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }	
	return 0;
}

