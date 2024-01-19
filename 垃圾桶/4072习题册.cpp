#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
array<int, 3> t[N];
long long ans[N];
multiset<array<int, 3>> msa[10], msb[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i][1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i][2];
        msb[t[i][2]].insert(t[i]);
    }
    for (int i = 1; i <= n; i++) {
        msa[t[i][1]].insert(t[i]);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        // cerr<<"this is "<<i<<endl;
        int c;
        cin >> c;
        if (msa[c].empty() && msb[c].empty())
            continue;
        if (msa[c].empty()) {
            // cerr<<i<<" "<<"Hello\n";
            ans[i] += (*msb[c].begin())[0];
            // cerr<<"ans[1]: "<<ans[i]<<'\n';
            auto it = msb[c].begin();
            auto temp = *it;
            msb[c].erase(it);
            it = msa[temp[1]].find(temp);
            msa[temp[1]].erase(it);
            continue;
        }
        if (msb[c].empty()) {
            ans[i] += (*msa[c].begin())[0];
            auto it = msa[c].begin();
            auto temp = *it;
            msa[c].erase(it);
            it = msb[temp[2]].find(temp);
            msb[temp[2]].erase(it);
            continue;
        }
        // cerr<<"Hello\n";
        auto ita = msa[c].begin();
        auto itb = msb[c].begin();
        if ((*ita)[0] < (*itb)[0]) {
            ans[i] += (*ita)[0];
            auto temp = *ita;
            // cerr<<"temp:"<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<"\n";
            auto it = msb[temp[2]].find(temp);
            assert(it != msb[temp[2]].end());
            msa[c].erase(ita);
            msb[temp[2]].erase(it);
        } else {
            ans[i] += (*itb)[0];
            auto temp = *itb;
            auto it = msa[temp[1]].find(temp);
            assert(it != msa[temp[1]].end());
            msb[c].erase(itb);
            msa[temp[1]].erase(it);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (ans[i] == 0)
            cout << "-1 ";
        else
            cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}