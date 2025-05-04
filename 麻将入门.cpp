#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[3];
	for (int i=0; i<3; i++) {
		cin >> a[i];
	}	
	sort(a, a+3);	
	if (a[0]==a[1] && a[1]==a[2]) {
		cout << "Yes\n";
		return 0;
	}
	if (a[1]==a[0]+1 && a[2]==a[1]+1) {
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";
	return 0;
}

