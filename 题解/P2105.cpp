#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, K;
    cin >> n >> m >> K;

    vector<bool> visx(n), visy(m), visd1(n + m - 1), visd2(40005);

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        visx[x] = visy[y] = visd1[x + y] = visd2[x - y + 20005] = true;
    }   

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visx[i] || visy[j] || visd1[i + j] || visd2[i - j + 20005]) continue;
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}