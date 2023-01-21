#include <bits/stdc++.h>

using namespace std;

const int N = 30005;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int test = 1; test <= tt; test++) {
        int n;
        cin >> n;
        int c[3] = {0, 0, 0};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            c[a[i] % 3]++;
        }
        int sum = c[0] + c[1] + c[2];
        int goal = sum / 3;
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            while (c[i] > goal) {
                c[i]--;
                c[(i + 1) % 3]++;
                ++ans;
            }
            while (c[(i + 1) % 3] < goal) {
                c[i]--;
                c[(i + 1) % 3]++;
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}