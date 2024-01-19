#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<vector<vector<char>>, int> cnt;
    for (int i = 0; i < n; i++) {
        vector<vector<char>> f(8, vector<char>(8));
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> f[i][j];
            }
        }
        cout << ++cnt[f] << '\n';
    }   
    return 0;
}