#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

int n;
double p;

double solve(int k) {
	if (k==1) {
		return n;
	}
	double p1=1-pow(1-p, k);
	double res=n*p1+n/k;
//	db(k), db(p1), db(res), el;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p;
	int ans=n;
	double mn=1e12;
	for (int i=1; i*i<=n; i++) {
		if (n%i==0) {
			int j=n/i;
			{
				double res=solve(i);
				if (res<mn) {
					mn=res;
					ans=i;
				}
				else if (res==mn) {
					ans=min(ans, i);
				}
			}
			if (i!=j) {
				double res=solve(j);
				if (res<mn) {
					mn=res;
					ans=j;
				}
				else if (res==mn) {
					ans=min(ans, j);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

