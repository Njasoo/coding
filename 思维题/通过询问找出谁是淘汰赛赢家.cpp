#include <bits/stdc++.h>

using namespace std;

/*
四个四个地去比较, 那么胜场一定是{t, t, t + 1, t + 2}的分布
注意到相邻的两个参赛者胜场一定不同, 所以一定能在两次之内算到相邻四场的胜者

每四个参赛者选出胜者, 胜者成为下一回合的参赛者, 按照上面的规则继续判断

每一轮判断, 都可以使得总参赛者的数量变成四分之一
所以一共需要(2 ^ n) / 4 * 2 + (2 ^ n % 2 == 2)
*/

void solve() {
    int n;
    cin >> n;
    vector<int> contestants(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        contestants[i] = i + 1;
    }
    while(contestants.size() >= 4) {
        int number_of_contestants = contestants.size();
        vector<int> next_round;
        for (int i = 0; i < number_of_contestants; i += 4) {
            cout << "? " << contestants[i] << " " << contestants[i + 2] << endl;
            int response;
            cin >> response;
            if (response == 0) {
                cout << "? " << contestants[i + 1] << " " << contestants[i + 3] << endl;
                cin >> response;
                if (response == 1) {
                    next_round.push_back(contestants[i + 1]);
                } else {
                    next_round.push_back(contestants[i + 3]);
                }
            } else if (response == 1) {
                cout << "? " << contestants[i] << " " << contestants[i + 3] << endl;
                cin >> response;
                if (response == 1) {
                    next_round.push_back(contestants[i]);
                } else {
                    next_round.push_back(contestants[i + 3]);
                }
            } else {
                cout << "? " << contestants[i + 2] << " " << contestants[i + 1] << endl;
                cin >> response;
                if (response == 1) {
                    next_round.push_back(contestants[i + 2]);
                } else {
                    next_round.push_back(contestants[i + 1]);
                }
            }
        }
        contestants = next_round;
    }
    if (contestants.size() == 2) {
        cout << "? " << contestants[0] << " " << contestants[1] << endl;
        int response;
        cin >> response;
        if (response == 1) {
            cout << "! " << contestants[0] << endl;
        } else {
            cout << "! " << contestants[1] << endl;
        }
    } else {
        cout << "! " << contestants[0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }      
    return 0;
}