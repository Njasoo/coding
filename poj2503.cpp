#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> hs;
char s[1005], a[1005], b[1005];

int main() {
    while (gets(s) && s[0] != '\0') {
        sscanf(s, "%s %s", a, b);
        hs[b] = a;
    }
    while (gets(s)) {
        if (hs.find(s) == hs.end()) {
            printf("eh\n");
        } else {
            cout << hs[s] << '\n';
        }
    }
    return 0;
}