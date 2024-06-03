def solve():
    n=int(input())
    a=list(map(int,input().split()))
    ans=0
    for i in range(n):
        ans+=a[i]

if __name__=='__main__':
    t=int(input())
    while t!=0:
        t-=1
        solve()