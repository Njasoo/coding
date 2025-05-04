def sieve(n):
    global minp,primes
    minp=[0]*(n+1)
    primes=[]
    for i in range(2,n+1):
        if minp[i]==0:
            minp[i]=i
            primes.append(i)
        for p in primes:
            if p*i>n:
                break
            minp[i*p]=p
            if minp[i]==p:
                break