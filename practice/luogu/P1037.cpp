#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
string add(string s1, string s2) {
    int m = max(s1.size(), s2.size());
    vector<int> a(m), b(m);
    for (int i = 0; i < (int) s1.size(); i++) {
        a[i] = s1[s1.size() - 1 - i] - '0';
    }
    for (int i = 0; i < (int) s2.size(); i++) {
        b[i] = s2[s2.size() - 1 - i] - '0';
    }
    vector<int> c(m + 1);
    for (int i = 0; i < m; i++) {
        c[i] += a[i] + b[i];
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    string ans = "";
    if (c[m]) {
        ans += (char) (c[m] + '0');
    }
    for (int i = m - 1; i >= 0; i--) {
        ans += (char) (c[i] + '0');
    }
    return ans;
}
string sub(string s1, string s2) {
    bool change = false;
    auto fix = [&]() {
        if (s2.size() > s1.size() || (s1.size() == s2.size() && s1 < s2)) {
            s1.swap(s2);
            change = true;
        }
    };
    fix();
    int m = max(s1.size(), s2.size());
    vector<int> a(m), b(m);
    for (int i = 0; i < (int) s1.size(); i++) {
        a[i] = s1[s1.size() - 1 - i] - '0';
    }
    for (int i = 0; i < (int) s2.size(); i++) {
        b[i] = s2[s2.size() - 1 - i] - '0';
    }
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        c[i] = a[i] - b[i];
    }
    for (int i = 0; i < m; i++) {
        if (c[i] < 0) {
            c[i] += 10;
            c[i + 1]--;
        }
    }
    string ans = "";
    bool start = false;
    if (change) {
        ans += '-';
    }
    for (int i = m - 1; i >= 0; i--) {
        if (c[i]) {
            start = true;
        }
        if (start) {
            ans += (char) (c[i] + '0');
        }
    }
    return start ? ans : "0";
}
string mul(string s1, string s2) {
    int m = s1.size() + s2.size();
    vector<int> a(m), b(m);
    for (int i = 0; i < (int) s1.size(); i++) {
        a[i] = s1[s1.size() - 1 - i] - '0';
    }
    for (int i = 0; i < (int) s2.size(); i++) {
        b[i] = s2[s2.size() - 1 - i] - '0';
    }
    vector<int> c(m);
    for (int i = 0; i < (int) s1.size(); i++) {
        for (int j = 0; j < (int) s2.size(); j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < m - 1; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    string ans = "";
    bool start = false;
    for (int i = m - 1; i >= 0; i--) {
        if (c[i]) {
            start = true;
        }
        if (start) {
            ans += (char) (c[i] + '0');
        }
    }
    return start ? ans : "0";
}
struct Edge
{
    int v,nex;
}e[205];
int head[105];
int idx;
void add_edge(int u,int v)
{
    idx++;
    e[idx].v=v;
    e[idx].nex=head[u];
    head[u]=idx;
}
int tag[105];
int cnt;
int find_len(int u)
{
    cnt++;
    // cerr<<u<<endl;
    for(int i=head[u];i;i=e[i].nex)
    {
        if(tag[e[i].v])continue;
        tag[e[i].v]=1;
        find_len(e[i].v);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n;
    int k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
    }
    string ans="1";
    for(int i=0;i<n.size();i++)
    {
        int now=n[i]-'0';
        for(int j=0;j<10;j++)tag[j]=0;
        tag[now]=1;
        cnt=0;
        find_len(now);
        // cerr<<"cnt:"<<cnt<<endl;
        string scnt=to_string(cnt);
        ans=mul(ans,scnt);
    }
    cout<<ans<<'\n';
    return 0;
}