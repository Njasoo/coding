#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
// 我们需要找一条最短路，一次飞行看做是一个长度为1的边权
// 同时在最短路的基础上，我们要找其中纪念品价值总和最大的一条
// 题解说可以将纪念品的价值看做负边权，那么去往一个地点v的边权应该是1 - a[v]
// 那么起点的点权也要算上，建一个到其边权为0 - a[u]的虚根节点
// 但是这样就能保证找到的是最短路吗，好像找出来的可能是最长路
// 所以单次飞行的边权不应该是1，而是一个更大的值w使得我们可以忽略纪念品带来的影响
// 所以这个w应该要大于sigma(a[i]) >= 300 * 1e9 >= 1e12，这句话的意义可以视作一次飞行的价值比任何纪念品的价值都要重要
// 那么在跑最短路的时候就会优先考虑飞行次数，其次就是纪念品价值
// 记得INF > N * W，不然边权会溢出变为无穷大
const int N = 305;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long W = 1e12;
long long a[N];
long long f[N][N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if (ch == 'Y') {
                f[i][j] = W - a[j];
            } else {
                f[i][j] = INF;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        if (f[u][v] == INF) {
            cout << "Impossible\n";
        } else {
            // 现在的问题就是如何把飞行次数拿出来
            // f[u][v] = d * W - sigma(a[i]) 我们可以直接除以W，因为W > sigma(a[i])所以，后面那项相当于0，这也是这样设置的意义其二
            long long flight_num = f[u][v] / W + 1; // 记得加1，因为是-sigma(a[i]);会少了一
            // db(flight_num);
            // db(f[u][v]);
            // db(flight_num * W);
            long long tot_value = -(f[u][v] - flight_num * W) + a[u]; // 价值总和取出来的时候还是负的，记得加一个负号
            cout << flight_num << " " << tot_value << '\n';
        }
    }
    return 0;
}