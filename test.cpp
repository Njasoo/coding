#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long
#define double long double

typedef long long ll;
typedef pair<double, double> PII;

const int mod = 1e9 + 7;
const double EPS = 1e-12;
const int N = 1e6 + 10, INF = 1e18; 

int n, m;
double k;
PII a[N], b[N];
double c[N], d[N];

int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

bool check(double x)
{
    for(int i = 1; i <= n; i ++ ) {
        c[i] = (1.0 - x) * a[i].x - x * a[i].y;
    }
    for(int i = 1; i <= m; i ++ ) {
        d[i] = (x - 1.0) * b[i].x + x * b[i].y;
    }
    int cnt = 0;
    sort(c + 1, c + n + 1), sort(d + 1, d + m + 1);
    for(int i = 1; i <= n; i ++ ) {
        int l = 1, r = m + 1;
        while(l < r) {
            int mid=(l+r)>>1;
            if(d[mid] >= c[i]) r = mid;
            else l = mid + 1;
        }
        cnt += l - 1;
    }
    return cnt <= k;
}

void solve()
{
    cin>>n>>m>>k;
    k--;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    for(int i=1;i<=m;i++) cin>>b[i].x>>b[i].y;
    double l = 0.0, r = 1.0;
    while(r - l > EPS) {
        double mid = (l + r) / 2.0;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%.10Lf\n",r*100.0);
    return;
}

signed main()
{
    int t = 1;
    while(t -- ) solve();
    return 0;
}