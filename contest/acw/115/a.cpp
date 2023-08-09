#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int mina = 1e9;
    int a3 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mina = min(mina, a);
        if (i == 2) {
            a3 = a;
        }
    }
    cout << (mina ^ a3) + 2 << '\n';
    return 0;
}