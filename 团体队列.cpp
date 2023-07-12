#include <bits/stdc++.h>
using namespace std;
// q[0]为长队, 每个团队只要一个人去排, 现在团队里面没有人, 就第一个人去排长队霸位
// 团队里面有人就插在队员的后面
const int N = 1005;
queue<int> q[N];
map<int, int> team;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int id = 0;
    int t;
    while (cin >> t) {
        if (!t) break;
        team.clear();
        for (int i = 1; i <= t; i++) {
            int n;
            cin >> n;
            for (int j = 1; j <= n; j++) {
                int x;
                cin >> x;
                team[x] = i;
            }
        }
        for (int i = 0; i < N; i++) {
            while (!q[i].empty()) q[i].pop();
        }
        cout << "Scenario #" << ++id << '\n';
        string s;
        while (cin >> s) {
            if (s == "ENQUEUE") {
                int number;
                cin >> number;
                q[team[number]].push(number);
                if (q[team[number]].size() == 1) {
                    q[0].push(number);
                }
            } else if (s == "DEQUEUE") {
                int number = q[0].front(); // 他是团队里的谁不重要, 他只会告诉我们他这个团队是否依旧存在XD
                cout << q[team[number]].front() << '\n';
                q[team[number]].pop();
                if (q[team[number]].empty()) q[0].pop();
            } else {
                break;
            }
        }
        cout << '\n';
    }      
    return 0;
}