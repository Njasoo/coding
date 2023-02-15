#include <bits/stdc++.h>
using namespace std;
struct Trie {
    // 注意，该模板的下标从零开始
    // static const 和 const static 其实是一样的
    int id; // 字母和数字的最大ascii码为122，可以看做是边的id，或者是to结点的id
    // 第一维是id，第二维是要去的结点
    int tr[3000005][130], cnt[3000005];
    Trie() {
        printf("hello\n");
        id = 0;
        memset(tr, 0, sizeof(tr));
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(char *str) {
        int p = 0;
        int len = strlen(str);
        printf("len = %d\n", len);
        for (int i = 0; i < len; i++) {
            int ch = str[i];
            if (!tr[p][ch]) { // 判断p -> ch这条边是否存在
                tr[p][ch] = ++id;
                cnt[tr[p][ch]]++;
            }
            p = tr[p][ch]; // to
        }
    }
    bool find(char *str) {
        int len = strlen(str);
        printf("len = %d\n", len);
        int p = 0;
        for (int i = 0; i < len; i++) {
            int ch = str[i];
            if (!tr[p][ch]) return 0;
            p = tr[p][ch];
        }
        return 1;
    }
};
char s[1505];
int main() {
    int n;
    scanf("%d", &n);
    Trie tree;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        if (!tree.find(s + 1)) {
            tree.insert(s + 1);
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}