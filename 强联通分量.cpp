#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <functional>
#include <iomanip>

using namespace std;

vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while (!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}

void debug_out(vector<string> __attribute__((unused)) args, // __attribute__((unused)): avoid warning
__attribute__ ((unused)) int idx,
__attribute__((unused)) int LINE_NUM) { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if (idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " == " << ss.str(); // str() temporary string
    debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 114514;
#endif

struct FastIO { // fast IO stream
    // https://en.cppreference.com/w/cpp/types/is_integral
    // https://en.cppreference.com/w/cpp/types/enable_if
    template<typename T, typename enable_if<is_integral<T>::value, int>::type = 0> // reading integrals
    inline const FastIO& operator>>(T& x) const {
        x = 0;
        bool flag = 0;
        char ch = getchar();
        while (!isdigit(ch)) {
            if (ch == '-') flag = 1;
            ch = getchar();
        }
        while (isdigit(ch)) {
            x = x * 10 + ch - '0';
            ch = getchar();
        }
        if (flag) x = -x;
        return *this;
    }

    inline const FastIO& operator>>(__int128_t& x) const {
        x = 0;
        bool flag = 0;
        char ch = getchar();
        while (!isdigit(ch)) {
            if (ch == '-') flag = 1;
            ch = getchar();
        }
        while (isdigit(ch)) {
            x = x * 10 + ch - '0';
            ch = getchar();
        }
        if (flag) x = -x;
        return *this;
    }

    inline const FastIO& operator>>(char& c) const {
        c = getchar();
        while (c == ' ' || c == '\n') c = getchar();
        return *this;
    }

    inline const FastIO& operator>>(std::string& s) const {
        char ch = getchar();
        while (ch == ' ' || ch == '\n') ch = getchar();
        while (ch != ' ' && ch != EOF && ch != '\n') {
            s += ch;
            ch = getchar();
        }
        return *this;
    }

    inline const FastIO& operator>>(char s[]) const {
        int p = 0;
        char ch = getchar();
        while (ch == ' ' || ch == '\n') ch = getchar();
        while (ch != ' ' && ch != EOF && ch != '\n') {
            s[p++] = ch;
            ch = getchar();
        }
        s[p] = '\0';
        return *this;
    }

    // https://en.cppreference.com/w/cpp/types/is_floating_point
    template<typename T, typename enable_if<is_floating_point<T>::value, int>::type = 0> // reading floating point
    inline const FastIO& operator>>(T& x) const {
        x = 0;
        bool flag = 0;
        char ch = getchar();
        while (!isdigit(ch)) {
            if (ch == '-') flag = 1;
            ch = getchar();
        }
        while (isdigit(ch)) {
            x = x * 10 + ch - '0';
            ch = getchar();
        }
        if (ch == '.') {
            T factor = 0.1;
            ch = getchar();
            while (isdigit(ch)) {
                x = x + (ch - '0') * factor;
                ch = getchar();
                factor *= 0.1;
            }
        }
        if (flag) x = -x;
        return *this;
    }

    // output
    template<typename T, typename enable_if<is_integral<T>::value, int>::type = 0>
    inline const FastIO& operator<<(T x) const {
        char s[128];
        int p = 0;
        if (x == 0) s[p++] = '0';
        while (x) {
            s[p++] = x % 10 + '0';
            x /= 10;
        }
        while (p) {
            putchar(s[--p]);
        }
        return *this;
    }

    inline const FastIO& operator<<(__int128_t x) const {
        char s[256];
        int p = 0;
        if (x == 0) s[p++] = '0';
        while (x) {
            s[p++] = x % 10 + '0';
            x /= 10;
        }
        while (p) {
            putchar(s[--p]);
        }
        return *this;
    } 

    inline const FastIO& operator<<(const char& x) const {
        putchar(x);
        return *this;
    }

    inline const FastIO& operator<<(const char s[]) const {
        while (*s) {
            putchar(*s++);
        }
        return *this;
    }

    inline const FastIO& operator<<(const string& s) const {
        for (const char& c : s) {
            putchar(c);
        }
        return *this;
    }
} fin, fout;
#define cin fin
#define cout fout

const int N = 1e4 + 5;
vector<int> g[N], ans[N];
int dfn[N], s[N], low[N], belong[N];
int top, id, cnt;
bool instack[N], vis[N];

void dfs(int u) {
    dfn[u] = low[u] = ++id;
    s[++top] = u;
    instack[u] = 1;
    for (auto v : g[u]) {
        if (!dfn[v]) dfs(v);
        if (instack[v]) low[u] = min(low[u], low[v]);
    }
    debug(u, dfn[u], low[u]);
    if (dfn[u] == low[u]) {
        cnt++;
        ans[cnt].push_back(u);
        while (s[top] != u) { // 判断条件不是栈空
            belong[s[top]] = cnt;
            instack[s[top]] = 0;
            ans[cnt].push_back(s[top]);
            top--;
        }
        top--;
        belong[u] = cnt;
        instack[u] = 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i);
    }
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; i++) {
        sort(ans[i].begin(), ans[i].end());
    }
    for (int i = 1; i <= n; i++) {
        if (vis[belong[i]]) continue;
        vis[belong[i]] = 1;
        for (auto v : ans[belong[i]]) {
            cout << v << " ";
        }
        cout << '\n';
    }
    return 0;
}