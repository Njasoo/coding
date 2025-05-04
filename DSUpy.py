class DSU:
    def __init__(self, n):
        self.f=[]
        self.siz=[]
        for i in range(n):
            self.f.append(i)
            self.siz.append(1)

    def find(self, x):
        while x!=self.f[x]:
            self.f[x]=self.f[self.f[x]]
            x=self.f[x]
        return x

    def merge(self, x, y):
        x=self.find(x)
        y=self.find(y)
        if x==y:
            return None
        self.f[y]=x
        self.siz[x]+=self.siz[y]

    def same(self, x, y):
        return self.find(x)==self.find(y)

    def size(self, x):
        return self.siz[self.find(x)]