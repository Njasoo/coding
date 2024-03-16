#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> id(N);
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        P--;
        id[P] = i;
    }   
    int Q;
    cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        if (id[A] < id[B]) {
            cout << A + 1 << "\n";
        } else {
            cout << B + 1 << "\n";
        }
    }
    return 0;
}