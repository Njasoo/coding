    #include <bits/stdc++.h>

    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        string s;
        cin >> s;
        int pos = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '.') {
                pos = i;
                break;
            }
        }
        cout << s.substr(pos + 1) << '\n';
        return 0;
    }