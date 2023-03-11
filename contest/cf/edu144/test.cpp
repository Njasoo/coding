#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 10000;
    string s = "";
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            s += "FB";
        } else if (i % 3 == 0) {
            s += "F";
        } else if (i % 5 == 0) {
            s += "B";
        }
    }   
    cout << s << '\n';
    return 0;
}