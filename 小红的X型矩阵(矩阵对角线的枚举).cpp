#include <bits/stdc++.h>

using namespace std;

#define ts cerr << "LINE " << __LINE__ << ": " << "hi" << endl 
#define db(x) cerr << (#x) << "=" << x << " "
#define el cerr << endl
#define ll long long
#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define N 1005

int tot, n;
char a[N][N];
int id1[N][N], id2[N][N];
map<int, int> sum1[2], sum2[2];

int calc(int x, int y) {
    // if(x==1 && y==1)
    //     db(sum1[0][id1[x][y]]), db(sum2[0][id2[(x+1)%n][(y+1)%n]]), db(sum1[1][id1[x][y]]), db(sum2[1][id2[(x+1)%n][(y+1)%n]]), el;
    if(n%2)
        return sum1[0][id1[x][y]]+sum2[0][id2[x][y]]-(a[x][y]=='0')+tot-sum1[1][id1[x][y]]-sum2[1][id2[x][y]]+(a[x][y]=='1');
    else
        return sum1[0][id1[x][y]]+sum2[0][id2[(x+1)%n][y]]+tot-sum1[1][id1[x][y]]-sum2[1][id2[(x+1)%n][y]];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int tmp=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            id1[(i+j)%n][j%n]=tmp;
            id2[(i+j)%n][(n-j)%n]=tmp;
        }
        tmp++;
    }

    // for(int i=0; i<n; i++)
    //     for(int j=0; j<n; j++)
    //         cout << id1[i][j] << " \n"[j==n-1];
    // cout << "\n";
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<n; j++)
    //         cout << id2[i][j] << " \n"[j==n-1];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            tot+=a[i][j]-'0';
            sum1[a[i][j]-'0'][id1[i][j]]++;
            sum2[a[i][j]-'0'][id2[i][j]]++;
        }
    }

    int ans=n*n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans=min(ans, calc(i, j));
        }
    }
    cout << ans << '\n';

    return 0;
}