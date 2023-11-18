#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 5;
char f[255][N];
int tempa[N], tempb[N], tempc[N];

void add(char a[], char b[]) {
    memset(tempc, 0, sizeof(tempc));
    memset(tempa, 0, sizeof(tempa));
    memset(tempb, 0, sizeof(tempb));
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
    int final_len = 0;
    if (tempc[len]) a[final_len++] = tempc[len] + '0';    
    for (int i = len - 1; i >= 0; i--) {
        a[final_len++] = tempc[i] + '0';
    }
    a[final_len] = '\0';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    strcpy(f[0], "1");
    strcpy(f[1], "1");
    strcpy(f[2], "3");
    for (int i = 3; i <= 250; i++) {
        strcpy(f[i], "0");
        add(f[i], f[i - 1]);
        add(f[i], f[i - 2]);
        add(f[i], f[i - 2]);
    }
    while (cin >> n) {
        cout << f[n] << '\n';
    }
    return 0;
}