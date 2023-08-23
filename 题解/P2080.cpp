#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

// O(2 ^ n), 算上剪枝就不知道了

const int N = 35;
int n, v, ans = 1e9;
int a[N], b[N];
bool vis[N];

void func(int cura, int curb, int lst) {
    if (ans == 0) return;
    if (cura + curb >= v) {
        ans = min(ans, abs(cura - curb));
        if (ans == 0) return;
    }
    for (int i = lst + 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        func(cura + a[i], curb + b[i], i);
        vis[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    func(0, 0, 0);
    if (ans == 1e9) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}