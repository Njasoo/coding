#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 105;
int a[N], cnt[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= k; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] <= k) {
				cnt[a[i]]++;
			}
		}
		bool flag = true;
		for (int i = 1; i <= k; i++) {
			if (cnt[i] == 0) {
				flag = false;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}	
	return 0;
}

