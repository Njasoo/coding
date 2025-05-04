#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

const int N=1005;
int a[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=i; j++) {
				cin >> a[i][j];
			}
		}	
		bool flag=1;
		for (int i=1; i<n; i++) {
			for (int j=1; j<=i; j++) {
				if (a[i][j]<=a[i+1][j] && a[i][j]<=a[i+1][j+1]) {
				}
				else {
					flag=0;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		cout << (flag?"Yes":"No") << "\n";
	}
	return 0;
}

