#include <bits/stdc++.h>
using namespace std;
const int MN = 3000;
int a[MN + 5];
char s[MN + 5];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] != '.') continue;
        int l = i, r = i;
        int disL = 0, disR = 0;
        bool saveL = 0, saveR = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (s[j] == 'L') {
                saveL = 1;
                break;
            }
            if (s[j] == 'R') {
                disL = i - j;
                break;
            }
        }
        for (int j = i + 1; j <= n; j++) {
            if (s[j] == 'R') {
                saveR = 1;
                break;
            }
            if (s[j] == 'L') {
                disR = j - i;
                break;
            }
        }
        if (disL == disR || (saveL && saveR)) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}