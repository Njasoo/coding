#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
vector<int> p[N];
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            p[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            p[a].push_back(b);
            p[b].push_back(a);
        }
    }   
    return 0;
}