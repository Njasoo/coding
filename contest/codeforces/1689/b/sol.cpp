#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
void solve()
{
  int n;
  cin>>n;
  vector<int> p(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>p[i];
  }
  if(n==1)
  {
    cout<<-1<<endl;
    return;
  }
  set<int> s;
  for(int i=1;i<=n;i++)
  {
    s.insert(i);
  }
  for(int i=1;i<=n-2;i++)
  {
    int x=*s.begin();
    if(x==p[i])
    {
      x=*next(s.begin());
    }
    cout<<x<<" ";
    s.erase(x);
  }
  int a=*s.begin();
  int b=*s.rbegin();
  if(a==p[n-1] || b==p[n])
  {
    swap(a,b);
  }
  cout<<a<<" "<<b<<endl;
}
int main() 
{
  int tt;
  cin>>tt;
  while(tt--)
  {
    solve();
  }
  return 0;
}