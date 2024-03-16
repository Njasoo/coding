#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }   
    int ans = 0;
    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {
            if (S[i][j] == '#') continue;
            int x = i, y = j;
            bool ok = true;
            for (char c : T) {
                if (c == 'L') y--;
                if (c == 'U') x--;
                if (c == 'R') y++;
                if (c == 'D') x++;
                if (S[x][y] == '#') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}