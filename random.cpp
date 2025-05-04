#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int iter = 100;
    while (iter--) {
        ofstream fout("in");
        fout << 1 << "\n";
        string s;
        for (int i = 1; i <= 100; i++) {
            int d;
            if (i == 1) {
                d = rng() % 9 + 1;
            } else {
                d = rng() % 10;
            }
            s += char(d + '0');
        }
        fout << s << "\n";
        fout.close();
        system("sol < in > out");
        system("judge < out");
        system("pause");
    }
    return 0;
}