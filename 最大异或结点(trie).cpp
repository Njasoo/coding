#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

const int N=1e5+5;
vector<int> adj[N];
int idx,tr[3100005][2],cnt[3100005],a[N];
string sa[N];

void insert(const string& s){
    int p=0;
    for(int c:s){
        c-='0';
        if(!tr[p][c]){
            tr[p][c]=++idx;
        }
        p=tr[p][c];
        cnt[p]++;
    }
}

void erase(const string& s){
    int p=0;
    for(int c:s){
        c-='0';
        p=tr[p][c];
        cnt[p]--;
    }
}

int query(const string& s){
    int p=0;
    for(int c:s){
        c-='0';
        if(!tr[p][c])return 0;
        p=tr[p][c];
    }
    return cnt[p];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll t=a[i];
        string tmp;
        while(t){
            tmp+=char(t%2+'0');
            t/=2;
        }
        while(tmp.size()<31)tmp+='0';
        reverse(tmp.begin(),tmp.end());
        sa[i]=tmp;
        // db(i),db(sa[i]),el;
        insert(sa[i]);
    }
    for(int i=1;i<=n;i++){
        int f;
        cin>>f;
        if(f!=-1){
            adj[i].push_back(f);
            adj[f].push_back(i);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll best_ans=(1LL<<31)-1;
        // db(bitset<32>(best_ans)),el;
        best_ans^=a[i];
        string tmp;
        while(best_ans){
            tmp+=char(best_ans%2+'0');
            best_ans/=2;
        }
        while(tmp.size()<31)tmp+='0';
        assert(tmp.size()==31);
        reverse(tmp.begin(),tmp.end());
        string cur;
        erase(sa[i]);
        for(int v:adj[i]){
            erase(sa[v]);
        }
        for(char c:tmp){
            cur+=c;
            if(!query(cur)){
                cur.pop_back();
                cur+=char(((c-'0')^1)+'0');
            }
        }
        // db(cur),el;
        ll dcur=0;
        for(char c:cur){
            dcur=dcur*2+(c-'0');
        }
        ans=max(ans,a[i]^dcur);
        insert(sa[i]);
        for(int v:adj[i]){
            insert(sa[v]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}