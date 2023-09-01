#include <iostream>
#include <cstring>

using namespace std;

#ifndef ONLINE_JUDGE
#define debug printf
#else
#define debug(...) 114514
#endif

const int N = 2e5 + 5;
char s[N];
int st[N];
int top;

void solve() {
    top = 0;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    st[top] = 1;
    int add = 0;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '+') {
            add++;
            if (top == 0) {
                st[++top] = 1;
                continue;
            }
            if (st[top] == 0) st[++top] = 0;
            else st[++top] = 1;
        } else if (s[i] == '-') {
            top--;
        } else if (s[i] == '1') {
            add = 0;
            if (st[top] == 1) {
                continue;
            }
            flag = 0;
            break;
        } else {
            if (top < 2) {
                flag = 0;
                break;
            } else {
                if (st[top] == 0) {
                    continue;
                } else {
                    if (add > 0) {
                        add--;
                        st[top] = 0;
                    } else {
                        flag = 0;
                        break;
                    }
                }
            }
        }
    }
    if (flag) puts("YES");
    else puts("NO");
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        solve();
    }
    return 0;
}