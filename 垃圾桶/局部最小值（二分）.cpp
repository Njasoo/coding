#include<bits/stdc++.h>
using namespace std;

#define db(x) cerr<<(#x)<<"="<<x<<" "
#define el cerr<<endl

const int N=1e6+5;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=n;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]<a[mid-1] && a[mid]<a[mid+1]){
            ans=a[mid];
            break;
        }
        if(a[mid]>a[mid-1]){
            r=mid;
        }else if(a[mid]>a[mid+1]){
            l=mid;
        }
    }
    cout<<ans<<'\n';
    return 0;
}