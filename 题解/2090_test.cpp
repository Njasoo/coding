#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (b > a) swap(a, b);
    int r = a % b;
    int cnt = 1;
    while (r) {
        cnt++;
        a = b;
        b = r;
        r = a % b;
    }
    cout << b << '\n';
    cout << cnt << '\n';
    cerr << b << " " << r << endl;
    return 0;
}