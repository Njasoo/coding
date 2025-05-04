def sieve(n):
    global primes, minp
    minp=[0]*(n+1)
    primes=[]
    for i in range(2, n+1):
        if minp[i]==0:
            primes.append(i)
            minp[i]=i
        for p in primes:
            if i*p>n:
                break
            minp[i*p]=p
            if minp[i]==p:
                break
sieve(3*10**6)

ans=0
for i in range(len(primes)):
    for j in range(i+1, len(primes)):
        cnt=primes[i]**2*primes[j]**2
        if cnt>23333333333333:
            break
        if 2333<=cnt<=23333333333333:
            ans+=1
print(ans)
