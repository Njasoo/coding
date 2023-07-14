#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int nex[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    int j = 0; // 当前border长度
    // j + 1 -> j, j -> j - 1
    for (int i = 2; i <= m; i++) {
        while (j && s2[i] != s2[j + 1]) j = nex[j];
        if (s2[i] == s2[j + 1]) j++;
        nex[i] = j;
    }
    j = 0;
    for (int i = 1; i <= n; i++) {
        while (j > 0 && s1[i] != s2[j + 1]) j = nex[j];
        if (s1[i] == s2[j + 1]) j++;
        if (j == m) {
            cout << i - m + 1 << '\n';
            j = nex[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << nex[i] << " \n"[i == m];
    }
    return 0;
}