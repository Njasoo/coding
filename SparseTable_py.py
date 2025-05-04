class SparseTable:
    def __init__(self, a, func):
        self.a=a
        self.n=len(a)
        self.lg=[0]*(self.n+1)
        self.func=func
        self.st=[[0 for j in range(25)] for i in range(self.n)]
        for i in range(2, self.n+1):
            self.lg[i]=self.lg[i>>1]+1
        for i in range(self.n):
            self.st[i][0]=a[i]
        for j in range(1, 25):
            # i+(1<<j)-1<n
            # i<n+1-(1<<j)
            for i in range(0, self.n-(1<<j)+1):
                self.st[i][j]=func(self.st[i][j-1], self.st[i+(1<<(j-1))][j-1])
    def query(self, l, r):
        k=self.lg[r-l+1]
        return self.func(self.st[l][k], self.st[r-(1<<k)+1][k])