#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<vector<int>> Q(n, vector<int>(d)), K(d, vector<int>(n)), V(n, vector<int>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> Q[i][j];
        }
    }   
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < d; i++) {
            cin >> K[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> V[i][j];
        }
    }
    vector<int> W(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
    vector<vector<int>> ans1(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < d; k++) {
                ans1[i][j] += Q[i][k] * K[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans1[i][j] *= W[i];
        }
    }
    // (n, d);
    vector<vector<int>> ans(n, vector<int>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] += ans1[i][k] * V[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}