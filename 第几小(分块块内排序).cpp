#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl
#define sz(x) (int)(x).size()
typedef long long ll;

const int N=1e5+5;
int a[N],b[N],bk[N],l[505],r[505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }   
    int bl=sqrt(n);
    int cb=n/bl;
    for(int i=1;i<=cb;i++){
        l[i]=r[i-1]+1;
        r[i]=l[i]+bl-1;
    }
    if(r[cb]<n){
        cb++;
        l[cb]=r[cb-1]+1;
        r[cb]=n;
    }
    for(int i=1;i<=cb;i++){
        for(int j=l[i];j<=r[i];j++){
            bk[j]=i;
        }
        sort(b+l[i],b+r[i]+1);
    }
    int m;
    cin>>m;
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            int p1=lower_bound(b+l[bk[x]],b+r[bk[x]]+1,a[x])-b;
            for(int i=p1;i<r[bk[x]];i++){
                b[i]=b[i+1];
            }
            a[x]=y;
            int p2=lower_bound(b+l[bk[x]],b+r[bk[x]],a[x])-b;
            for(int i=r[bk[x]];i>p2;i--){
                b[i]=b[i-1];
            }
            b[p2]=a[x];
        }
        else{
            int x,y,p;
            cin>>x>>y>>p;
            int bs=bk[x],be=bk[y];
            int ans=0;
            if(bs==be){
                for(int i=x;i<=y;i++){
                    ans+=(a[i]<a[p]);
                }
            }
            else{
                for(int i=x;i<=r[bs];i++){
                    ans+=(a[i]<a[p]);
                }
                for(int i=l[be];i<=y;i++){
                    ans+=(a[i]<a[p]);
                }
                for(int i=bs+1;i<be;i++){
                    ans+=lower_bound(b+l[i],b+r[i]+1,a[p])-(b+l[i]);
                }
            }
            cout<<ans+1<<" ";
        }
    }
    return 0;
}