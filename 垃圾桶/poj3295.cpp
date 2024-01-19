#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

char s[1005], zimu[1005];
int n, top;
int st[1005], vis[1005], fuzhi[1005];

bool check() {
    for (int i = n - 1; i >= 0; i--) {
        // fprintf(stdout, "i = %d, s[i] = %c\n", i, s[i]);
        if (s[i] >= 'a' && s[i] <= 'z') {
            st[top++] = fuzhi[(int)s[i]];
        } else if (s[i] == 'A') {
            int x = st[--top];
            int y = st[--top];
            st[top++] = (x || y);
            // cout << "st[top - 1] = " << st[top - 1] << endl;
        } else if (s[i] == 'K') {
            int x = st[--top];
            int y = st[--top];
            st[top++] = (x && y);
            // cout << "st[top - 1] = " << st[top - 1] << endl;
        } else if (s[i] == 'N') {
            int x = st[--top];
            st[top++] = 1 ^ x;
            // cout << "st[top - 1] = " << st[top - 1] << endl;
        } else if (s[i] == 'C') {
            int x = st[--top];
            int y = st[--top];
            st[top++] = (!x) || y;
            // cout << "st[top - 1] = " << st[top - 1] << endl;
        } else if (s[i] == 'E') {
            int x = st[--top];
            int y = st[--top];
            st[top++] = (x == y);
            // cout << "st[top - 1] = " << st[top - 1] << endl;
        }
    }
    // cerr << "top = " << top << endl;
    // cerr << "st[top] = " << st[top] << endl;
    return st[top - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (scanf("%s", s) == 1) {
        if (strcmp(s, "0") == 0) break;
        memset(vis, 0, sizeof(vis));
        n = strlen(s);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (vis[(int)s[i]]) continue;
                vis[(int)s[i]] = 1;
                zimu[cnt++] = s[i];
            }
        }
        // cerr << "cnt = " << cnt << endl;
        bool ok = 1;
        for (int mask = 0; mask < (1 << cnt); mask++) {
            for (int i = 0; i < cnt; i++) {
                if (mask >> i & 1) {
                    fuzhi[(int)zimu[i]] = 1;
                } else {
                    fuzhi[(int)zimu[i]] = 0;
                }
            }
            if (!check()) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            printf("tautology\n");
        } else {
            printf("not\n");
        }
    }
    return 0;
}