#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int MAX_LEN = 51;
char str[MAX_LEN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.get(); // 拿掉换行符
    for (int i = 1; i <= n; i++) {
        cin.getline(str, MAX_LEN);
        puts(str);
    }
    return 0;
}