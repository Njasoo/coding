#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << " "
#define el cerr << "\n"

int f[5][5];

bool check() {
	for (int i=0; i<5; i++) {
		int cnt0=0;
		for (int j=0; j<5; j++) {
			cnt0+=(f[i][j]==0);
		}
		if (cnt0==0 || cnt0==5) {
			return 0;
		}
	}
	for (int j=0; j<5; j++) {
		int cnt0=0;
		for (int i=0; i<5; i++) {
			cnt0+=(f[i][j]==0);
		}
		if (cnt0==0 || cnt0==5) {
			return 0;
		}
	}
	int cnt0=0;
	for (int i=0; i<5; i++) {
		cnt0+=(f[i][i]==0);
	}
	if (cnt0==0 || cnt0==5) {
		return 0;
	}
	cnt0=0;
	for (int i=0; i<5; i++) {
		cnt0+=(f[i][4-i]==0);
	}
	if (cnt0==0 || cnt0==5) {
		return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	ll ans=0;
//	for (int mask=0; mask<(1<<25); mask++) {
//		if (__builtin_popcount(mask)!=12) {
//			continue;
//		}
//		for (int i=0; i<25; i++) {
//			if (mask>>i&1) {
//				f[i/5][i%5]=1;
//			} else {
//				f[i/5][i%5]=0;
//			}
//		}
//		if (check()) {
////			for (int i=0; i<5; i++) {
////				for (int j=0; j<5; j++) {
////					cout << f[i][j];
////				}
////				cout << endl;
////			}
////			cout << endl;
////			system("pause");
//			ans++;
//		}
//	}	
//	cout << ans << "\n";
	cout << "3126376\n";
	return 0;
}

