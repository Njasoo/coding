#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl
#define ll long long
#define ull unsigned long long

//dp[i][j]: 前i个队列, 选了j个元素的最小价值和
//时间复杂度: O(n*m*max(c_i)^2)
const int N=105, M=10005;
ll dp[M], g[M], c[N][N], sum[N][N], minc[N][N]; //minc[i][len]: 第i类, 范围大小为len的最小元素和

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int num=0;
    ll tot=0;
    for(int i=1; i<=n; i++) {
        cin >> c[i][0];
        num+=c[i][0];
        for(int j=1; j<=c[i][0]; j++) {
            cin >> c[i][j];
            tot+=c[i][j];
            sum[i][j]=sum[i][j-1]+c[i][j];
        }
    }
    int goal=num-m;
    // db(goal), el;
    // db(tot), el;
    //相同区间宽度的我只需要选择元素总和最小的就行了

    //100*100*100*100=1e8
    memset(minc, 0x3f, sizeof minc);
    for(int i=1; i<=n; i++) {
        for(int len=1; len<=c[i][0]; len++) {
            for(int l=1; l+len-1<=c[i][0]; l++) {
                int r=l+len-1;
                while(r<=c[i][0]) {
                    minc[i][len]=min(minc[i][len], sum[i][r]-sum[i][l-1]);
                    l++, r++;
                }
            }
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0]=0;

    //100*10000*100=1e8
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=goal; j++) {
            g[j]=dp[j];
        }
        for(int j=1; j<=goal; j++) {
            for(int len=1; len<=c[i][0] && len<=j; len++) {
                dp[j]=min(dp[j], g[j-len]+minc[i][len]);
            }
        }
    }
    cout << tot-dp[goal] << '\n';
    return 0;
}