#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define endl '\n'
#define sz(x) (int)(x).size()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    vector<long long> ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<"it is not a prime number\n";
            cout<<n<<"=";
            for(int j=2;n!=1;j++){
                while(n%j==0){
                    ans.push_back(j);
                    n/=j;
                }
            }
            for(int i=0;i<sz(ans)-1;i++){
                cout<<ans[i]<<"*";
            }
            cout<<ans.back()<<endl;
            return 0; 
        }
    }
    cout<<"it is a prime number\n";
    return 0;
}