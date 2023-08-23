#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int s[N], a[N], ans[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }      
    int top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && a[s[top]] <= a[i]) {
            top--;
        }
        ans[i] = top ? s[top] : 0;
        s[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}