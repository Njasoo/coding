#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (auto str : {"ACE", "CEG", "BDF", "DFA", "EGB", "FAC", "GBD"}) {
        if (str == s) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}