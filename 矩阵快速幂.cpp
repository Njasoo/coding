vector<vector<M>> operator*(vector<vector<M>> a, vector<vector<M>> b) {
    int n = a.size();
    int s = a[0].size();
    int m = b[0].size();
    vector<vector<M>> res(n, vector<M>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < s; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

vector<vector<M>> power(vector<vector<M>> a, long long b) {
    assert(b >= 0);
    int n = a.size();
    vector<vector<M>> res(n, vector<M>(n));
    for (int i = 0; i < n; i++) res[i][i] = 1; 
    while (b) {
        if (b % 2) res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}