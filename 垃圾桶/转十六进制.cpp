#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double n;
    cin >> n;
    int intergral_part = int(n);
    double decimal_part = n - int(n);
    string s;
    map<int, char> hs;
    for (int i = 10; i <= 15; i++) {
        hs[i] = char('A' - 10 + i);
    }
    while (intergral_part) {
        int num = intergral_part % 16;
        if (num < 10) {
            s += num + '0';
        } else {
            s += hs[num];
        }
        intergral_part /= 16;
    }
    reverse(s.begin(), s.end());
    s += '.';
    while (decimal_part) {
        decimal_part *= 16;
        int first_digit = int(decimal_part);
        if (first_digit < 9) {
            s += first_digit + '0';
        } else {
            s += hs[first_digit];
        }
        decimal_part -= first_digit;
    }
    cout << s << '\n';
    return 0;
}