#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, r, q;
int s[N], w[N];
int len_win, len_lose;
struct node {
    int s, id;
    bool operator < (const node &x) const {
        if (x.s == s) {
            return id < x.id;
        }
        return s > x.s;
    }
} t[N], temp_t[N], win[N], lose[N];
int k;
void merge() {
    int p = 1;
    int p_win = 1, p_lose = 1;
    while (p <= n * 2) {
        if (p_win == n + 1) {
            temp_t[p++] = lose[p_lose++];
            continue;
        }
        if (p_lose == n + 1) {
            temp_t[p++] = win[p_win++];
            continue;
        }
        if (win[p_win] < lose[p_lose]) {
            temp_t[p++] = win[p_win++];
        } else {
            temp_t[p++] = lose[p_lose++];
        }
    }
    // cerr << "ROUND: " << ++k << endl;
    // for (int i = 1; i <= n * 2; i++) {
    //     cerr << temp_t[i].s << " " << temp_t[i].id << endl;
    // }
    for (int i = 1; i <= n * 2; i++) {
        t[i] = temp_t[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r >> q;
    for (int i = 1; i <= n * 2; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n * 2; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n * 2; i++) {
        t[i] = {s[i], i};
    }
    sort(t + 1, t + 1 + n * 2);
    // for (int i = 1; i <= n * 2; i++) {
    //     cerr << t[i].s << " " << t[i].id << endl;
    // }
    for (int k = 1; k <= r; k++) {
        for (int i = 1; i <= n * 2; i += 2) {
            int p1 = w[t[i].id];
            int p2 = w[t[i + 1].id];
            if (p1 > p2) {
                t[i].s++;
                win[(i + 1) / 2] = t[i];
                // cerr << "win: " << win[len_win].s << " " << win[len_win].id << endl;
                lose[(i + 1) / 2] = t[i + 1];
            } else {
                t[i + 1].s++;
                win[(i + 1) / 2] = t[i + 1];
                // cerr << "win: " << win[len_win].s << " " << win[len_win].id << endl;
                lose[(i + 1) / 2] = t[i];
            }
        }
        merge();
    }
    // for (int i = 1; i <= n * 2; i++) {
    //     cerr << t[i].s << " ";
    // }
    // cerr << endl;
    // for (int i = 1; i <= n * 2; i++) {
    //     cerr << t[i].id << " \n"[i == n * 2];
    // }
    cout << t[q].id << '\n';
    return 0;
}