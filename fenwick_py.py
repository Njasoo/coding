class Fenwick:
    def __init__(self, n:int):
        self.n=n
        self.tr=[0]*(n+1)
    def add(self, x, k):
        x+=1
        while x<=self.n:
            self.tr[x]+=k
            x+=x&-x
    def sum(self, x):
        x+=1
        res=0
        while x!=0:
            res+=self.tr[x]
            x-=x&-x
        return res
    def query(self, l, r):
        assert l<=r
        return self.sum(r)-self.sum(l-1)