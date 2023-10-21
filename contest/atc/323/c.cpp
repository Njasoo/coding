#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 105;
long long a[N], score[N];
string s[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;   
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    long long max_score = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
        score[i] = i;
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'o') {
                score[i] += a[j];
            }
        }
        max_score = max(max_score, score[i]);
    }
    for (int i = 1; i <= n; i++) {
        vector<int> temp;
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'x') {
                temp.push_back(a[j]);
            }
        }
        sort(temp.begin(), temp.end(), greater<int>());
        int now = 0;
        long long temp_score = score[i];
        while (temp_score < max_score) {
            temp_score += temp[now++];
        }
        cout << now << '\n';
    }
    return 0;
}