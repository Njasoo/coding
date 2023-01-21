#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  string a,b;
  string c="";
  cin>>a>>b;
  sort(all(a));
  sort(all(b));
  int c1=0,c2=0;
  while(a.size() && b.size())
  {
    if((*a.begin()<*b.begin() && c1<k) || c2==k)
    {
      c1++;
      c2=0;
      c+=*a.begin();
      a.erase(a.begin());
    }
    else
    {
      c2++;
      c1=0;
      c+=*b.begin();
      b.erase(b.begin());
    }
  }
  cout<<c<<endl;
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