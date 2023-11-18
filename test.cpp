#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e3 + 5;
char f[N][N], temp[N];
int tempa[N], tempb[N], tempc[N];
char sa[N], sb[N];

void add(char a[], char b[]) {
    memset(tempc, 0, sizeof(tempc));
    int lena = strlen(a);
    int lenb = strlen(b);
    for (int i = 0; i < lena; i++) {
        tempa[i] = a[lena - 1 - i] - '0';
    }
    for (int i = 0; i < lenb; i++) {
        tempb[i] = b[lenb - 1 - i] - '0';
    }
    int len = max(lena, lenb);
    for (int i = 0; i < len; i++) {
        tempc[i] += tempa[i] + tempb[i];
        tempc[i + 1] = tempc[i] / 10;
        tempc[i] %= 10;
    }
    int start = 0;
    int final_len = 0;
    for (int i = len; i >= 0; i--) {
        if (tempc[i]) {
            if (!start) {
                start = 1;
            }
        }
        if (!start) continue;
        a[final_len++] = tempc[i] + '0';
    }
    a[final_len] = '\0';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> sa >> sb;
    add(sa, sb);
    cout << sa << '\n';
    return 0;
}