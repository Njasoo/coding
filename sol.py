def solve():
    n=int(input())
    a=list(map(int,input().split()))
    ans=0
    for i in range(len(a)):
        if a[i]%2==0:
            ans+=a[i]
        else:
            ans-=a[i]
    print(ans)

if __name__=="__main__":
    T=int(input())
    while T>0:
        T-=1
        solve()