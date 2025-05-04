#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	int res = rng() % (r - l + 1) + l;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int iter = 100;
	while (iter--) {
		ofstream fout("in");
		for(int i=1;i<=n;i++){
			cout<<ans<<"\n";
		}
		for(int i=1;i<=n;i++){
			f[i]=i;
			siz[i]=1;
		}
		fout.close();
		system("sol < in > out1");
		system("test < in > out2");
		int res = system("fc /N out1 out2");
		if (res) {
			// cerr << "test failed\n";
			break;
		} else {
			// cerr << "test passed\n";
		}
	}
	return 0;
}
