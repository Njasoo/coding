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

// 相当于是从某点求到i点的最长路径

const int N = 1e5 + 5;
vector<int> g[N];
int in[N], ans[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            ans[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) {
            in[v]--;
            if (in[v] == 0) {
                ans[v] = ans[u] + 1; // 最后更新的一个点
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}