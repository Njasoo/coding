#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long n;
    cin >> n;
    unsigned long long temp = n * (n + 1) * (2 * n + 1) + 3 * n * (n + 1);
    temp /= 12;
    cout << temp << '\n';
    return 0;
}