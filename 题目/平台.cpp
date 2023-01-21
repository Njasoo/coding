#include <bits/stdc++.h>

using namespace std;

int n;
int ans[1005][2]; // left and right
struct node {
  int h = 0, l, r, id;
}t[1005];

bool cmp1(node i, node j) {
  if (i.h == j.h) {
    return i.l < j.l;
  }
  return i.h > j.h;
}

bool cmp2(node i, node j) {
  return i.id < j.id;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i].h >> t[i].l >> t[i].r;
    t[i].id = i;
  }
  sort(t + 1, t + 1 + n, cmp1);
  // for (int i = 1; i <= n; i++) {
  //   cerr << t[i].h << " ";
  // }
  // cerr << endl;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (t[j].l < t[i].l && t[i].l < t[j].r) {
        if (ans[t[i].id][0] == 0) {
          ans[t[i].id][0] = t[j].id;
        } 
        // else if (t[j].h == t[ans[t[i].id][0]].h && t[j].id < ans[t[i].id][0]) {
        //   ans[t[i].id][0] = t[j].id;
        // }
      }
      if (t[j].l < t[i].r && t[i].r < t[j].r) {
        if (ans[t[i].id][1] == 0) {
          ans[t[i].id][1] = t[j].id;
        } 
        // else if (t[j].h == t[ans[t[i].id][1]].h && t[j].id < ans[t[i].id][1]) {
        //   ans[t[i].id][1] = t[j].id;
        // } 
        // else if (t[j].id < ans[t[i].id][1]) {
        //   ans[t[i].id][1] = t[j].id;
        // }
      }
    }
  }
  sort(t + 1, t + 1 + n, cmp2);
  for (int i = 1; i <= n; i++) {
    cout << ans[t[i].id][0] << " " << ans[t[i].id][1] << '\n';
  }
  return 0;
}