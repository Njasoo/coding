#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int a[N], b[N], ans[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string sa, sb;
    cin >> sa >> sb;
    int lena = (int) sa.size();
    int lenb = (int) sb.size();
    sa = ' ' + sa;
    sb = ' ' + sb;
    for (int i = 1; i <= lena; i++) {
        if (sa[lena - i + 1] >= 'a' && sa[lena - i + 1] <= 'z') {
            a[i] = sa[lena - i + 1] - 'a' + 10;
        } else {
            a[i] = sa[lena - i + 1] - '0';
        }
    }
    for (int i = 1; i <= lenb; i++) {
        if (sb[lenb - i + 1] >= 'a' && sb[lenb - i + 1] <= 'z') {
            b[i] = sb[lenb - i + 1] - 'a' + 10;
        } else {
            b[i] = sb[lenb - i + 1] - '0';
        }
    }
    int len = max(lena, lenb);
    for (int i = 1; i <= len; i++) {
        ans[i] += a[i] + b[i];
        ans[i + 1] += ans[i] / n;
        ans[i] %= n;
    }
    if (ans[len + 1]) len++;
    for (int i = len; i >= 1; i--) {
        if (ans[i] <= 9) cout << ans[i];
        else cout << (char) (ans[i] - 10 + 'a');
    }
    cout << "\n";
    return 0;
}