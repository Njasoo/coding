struct Edge {
    long long to, cost, nex;
} e[M];
int head[N], idx;

void add_edge(long long u, long long v, long long w) {
    idx++;
    e[idx].to = v;
    e[idx].cost = w;
    e[idx].nex = head[u];
    head[u] = idx;
}