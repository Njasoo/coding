#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
// greedy?
bool isprime(int x) {
    int num = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) num++;
    }
    return num == 0;
}
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        if (isprime(n)) {
            printf("%d\n", n);
        } else {
            map<int, int> cnt;
            for (int i = 2; n != 1; i++) {
                while (n % i == 0) {
                    n /= i;
                    cnt[i]++;
                }
            }
            long long ans = 0;
            while (!cnt.empty()) {
                long long temp = 1;
                for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
                    temp *= it->first;
                    it->second--;
                    if (it->second == 0) {
                        cnt.erase(it);
                    }
                }
                ans += temp;
            }
            printf("%lld\n", ans);
        }
    }   
    return 0;
}