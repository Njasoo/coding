#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N = 100005;
const ll MOD = 1e9 + 7;
pair<int, int> arr[3][N];
int len[3];
int cur_id1, cur_id2;
ll ans = 0;
struct Node {
	int l, w, c;
} t[N];
int lent;
int tr[N];

int my_lower_bound(int id, int val) {
	int lo = 1, hi = len[id];
	int res = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (arr[id][mid].first < val) {
			lo = mid + 1;
			res = mid;
		} else {
			hi = mid - 1;
		}
	}
	return res;
}

void clear() {
	for (int i = 1; i <= 100000; i++) {
		tr[i] = 0;
	}
}

void add(int x, int k) {
	while (x <= 100000) {
		tr[x]+=k;
		tr[x]%=MOD;
		x+=x&-x;
	}
}

ll sum(int x) {
	ll res=0;
	while (x) {
		res+=tr[x];
		x-=x&-x;
	}
	return res%MOD;
}

ll qry(int l, int r) {
	return sum(r)-sum(l-1);
}

bool cmp(Node i, Node j) {
	if (i.l==j.l) {
		return i.c==cur_id1;
	}
	return i.l<j.l;
}

ll calc(int id1, int id2) {
	cur_id1=id1, cur_id2=id2;
	ll res=0;
	lent = 0;
	clear();
	for (int i = 1; i <= len[id1]; i++) {
		lent++;
		t[lent].l=arr[id1][i].first;
		t[lent].w=arr[id1][i].second;
		t[lent].c=id1;
	}
	for (int i = 1; i <= len[id2]; i++) {
		lent++;
		t[lent].l=arr[id2][i].first;
		t[lent].w=arr[id2][i].second;
		t[lent].c=id2;
	}
	assert(lent==len[id1]+len[id2]);
	sort(t+1, t+1+lent, cmp);
	for (int i=1; i<=lent; i++) {
		if (t[i].c==id2) {
			add(t[i].w, 1);
		}
		else {
			res+=qry(t[i].w+1, 100000);
			res%=MOD;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, w, _c;
		cin >> l >> w >> _c;
		arr[_c][++len[_c]] = { l, w };
	}	
//	for (int i = 0; i < 3; i++) {
//		sort(arr[i] + 1, arr[i] + 1 + len[i]);
//	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				continue;
			}
			ans += calc(i, j);
			ans%=MOD;
		}
	}
	cout << ans << '\n';
	return 0;
}

