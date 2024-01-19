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
    while (intergral_part) {
        s += intergral_part % 2 + '0';
        intergral_part /= 2;
    }
    reverse(s.begin(), s.end());
    s += '.';
    while (decimal_part) {
        decimal_part *= 2;
        int first_digit = int(decimal_part);
        s += first_digit + '0';
        decimal_part = decimal_part - first_digit;
    }
    cout << s << '\n';
    return 0;
}