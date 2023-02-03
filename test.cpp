#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
// 区间修改？ 线段树？ 不是
// 考虑一下二进制好了
// 我只需要记录这个区间被修改了多少次，然后单次询问的时候再进行计算
// 但是如果是一直询问怎么办
// 那还是直接上线段树, 掏出几百万年前写过的线段树，现场写线段树，（我）怎么可能做得到
struct node {
  long long val, tag;
}t[800005];

void build(int id, int left, int right) {
  t[id].tag = 0;
  if (left == right) {
    t[id].val = 0;
    return;
  }
  int mid = (left + right) >> 1;
  build(id << 1, left, mid);
  build(id << 1 | 1, mid + 1, right);
  t[id].val = t[id << 1].val + t[id << 1 | 1].val;
}

void push_down(int id) {
  t[id << 1].tag += t[id].tag;
  t[id << 1 | 1].tag += t[id].tag;
  t[id].tag = 0;
}

void update(int id, int left, int right, int s, int e, long long k) {
  if (e < left || s > right) {
    return;
  }
  if (s <= left && right <= e) {
    t[id].tag += k;
    return;        
  }
  push_down(id);
  int mid = (left + right) >> 1;
  update(id << 1, left, mid, s, e, k);
  update(id << 1 | 1, mid + 1, right, s, e, k);
  t[id].val = t[id << 1].val + t[id << 1].tag * (mid - left + 1) + t[id << 1 | 1].val + t[id << 1 | 1].tag * (right - mid);
}

long long query(int id, int left, int right, int s, int e) {
  if (e < left || s > right) {
    return 0;
  }
  if (s <= left && right <= e) {
    return t[id].val + t[id].tag * (right - left + 1);
  }
  push_down(id);
  int mid = (left + right) >> 1;
  long long res = query(id << 1, left, mid, s, e) + query(id << 1 | 1, mid + 1, right, s, e);
  t[id].val = t[id << 1].val + t[id << 1].tag * (mid - left + 1) + t[id << 1 | 1].val + t[id << 1 | 1].tag * (right - mid);
  return res;
}
const int N = 2e5 + 5;
long long a[N];
long long tran(long long num) {
    long long res = 0;
    while (num) {
        res += num % 10;
        num /= 10;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        // memset(t, 0, sizeof(t)); // 直接一开始都是0，不用build了吧 还是build吧
        int n, q;
        cin >> n >> q;
        build(1, 1, n);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int qc = 1; qc <= q; qc++) {
            int op;
            cin >> op;
            if (op == 1) {
                int l, r;
                cin >> l >> r;
                update(1, 1, n, l, r, 1);
            } else {
                // 是不是经过若干次修改，就一定会变成某个个位数，应该很快就变成一个 个位数，所以我应该不用去算要多少次
                int x;
                cin >> x;
                long long tempa = a[x];
                // db(x);
                // db(t[x].val); // 啊为什么次数不对 query啦淦 
                long long cnt = query(1, 1, n, x, x);
                // db(cnt);
                for (long long i = 1; i <= cnt && (int) log10(tempa) + 1 >= 2; i++) { // log10(a) + 1是位数 
                    tempa = tran(tempa);
                }
                cout << tempa << '\n';
            }
        }
    }   
    return 0;
}