#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], b[N], pos_a[N], pos_b[N];
#define debug(x) cerr << #x << " = " << x << endl
void slove() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i], pos_a[a[i]] = i;
    for (int i = 1; i <= n; i++)cin >> b[i], pos_b[b[i]] = i;
    
    auto C2 = [](int n) { return n * (1 + n) / 2; };
    
    int L = min(pos_a[1], pos_b[1]);
    int R = max(pos_a[1], pos_b[1]);
    int ans = C2(L - 1) +  C2(n - R) + C2(max(0,R - L- 1));//mex = 1 的答案
    // cerr << "ans: " << ans << endl;
    for (int mex = 2; mex <= n; mex++) {
        int pa = pos_a[mex], pb = pos_b[mex];
        if (pa > pb)swap(pa, pb);
        // cerr << "pa: " << pa << " " << "pb: " << pb << endl;
        if ((L < pa && pa < R) ||( L < pb && pb < R)) {}
        else if (pa < L && R < pb) {
            ans += (L - pa) * (pb - R);// pa L R pb
            debug((L - pa) * (pb - R));
        }
        else if (pb < L) {
            cerr << "pa: " << pa << " " << "pb: " << pb << endl;
            cerr << "L: " << L << " " << "R: " << R << endl;
            ans += (L - pb) * (n - R + 1); // pa pb L R
            debug((L - pb) * (n - R + 1));
        }
        else if (pa > R) {
            ans += (L) * (pa - R); // L R pa pb
            debug((L) * (pa - R));
        }
        L = min(L, pa);
        R = max(R, pb);
        cerr << "ans: " << ans << endl;
        // cerr << "L: " << L << " " << "R: " << R << endl;
    }
    
    cout << ans + 1 << endl;
}
int main() {
    slove();
    return 0;
}