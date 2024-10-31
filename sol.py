tt=int(input())
while tt>0:
    tt-=1
    n=int(input())
    ans=0
    for i in range(64):
        if (1<<i)>=n:
            ans=1<<i
            break
    print(ans)