#include<bits/stdc++.h>
using namespace std;

//枚举排列，按照这个顺序从上到下，从左到右放

int id[15],A[15],B[15];
bool vis[15][15];
int N,H,W;
vector<int> temp;

bool place(int h,int w){
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(!vis[i][j]){
                for(int ii=i;ii<=i+h-1;ii++){
                    for(int jj=j;jj<=j+w-1;jj++){
                        if(ii>H || jj>W || vis[ii][jj])return 0;
                        vis[ii][jj]=1;
                    }
                }
                return 1;
            }
        }
    }
    return 1;
}

bool all_done(){
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(!vis[i][j])return 0;
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>H>>W;
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
        id[i]=i;
    }
    do{
        for(int mask=0;mask<(1<<N);mask++){
            temp.clear();
            for(int i=1;i<=H;i++){
                for(int j=1;j<=W;j++){
                    vis[i][j]=0;
                }
            }
            // if(id[0]==0 && id[1]==3 && id[2]==4 && (mask>>1&1) && !(mask>>2&1)){
            //     for(int i=0;i<N;i++){
            //         cout<<id[i]<<" ";
            //     }
            //     cout<<'\n';
            // }
            for(int i=0;i<N;i++){
                int x=A[id[i]],y=B[id[i]];
                if(mask>>i&1)swap(x,y);
                if(!place(x,y))break;
                if(all_done()){
                    cout<<"Yes\n";
                    return 0;
                }
            }
        }
    }while(next_permutation(id,id+N));
    cout<<"No\n";
    return 0;
}