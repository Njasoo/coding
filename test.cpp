#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<endl
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    multiset<int> ms;
    ms.insert(1);
    ms.insert(4);
    ms.insert(3);
    auto it=ms.lower_bound(2);
    cout<<*it<<endl;   
    return 0;
}