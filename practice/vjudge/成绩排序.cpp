#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    string name;
    int score;
}t[25];

bool cmp(node i,node j)
{
    if(i.score==j.score)return i.name<j.name;
    return i.score>j.score;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].name>>t[i].score;
    }
    sort(t+1,t+1+n,cmp);
    for(int i=1;i<=n;i++) cout<<t[i].name<<" "<<t[i].score<<endl;
    return 0;
}