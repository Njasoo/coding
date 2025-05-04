cnt=[0]*(10**6+1)
tr=[[0 for j in range(2)] for i in range(10**6+1)]
idx=0

def tobase2(x):
	res=""
	while x!=0:
		res+=str(x%2)
		x>>=1
	while len(res)<30:
		res+='0'
	res.reverse()
	return res

def modify(s,op):
	global cnt,tr,idx
	p=0
	for c in s:
		c=ord(c)-ord('0')
		if tr[p][c]==0:
			idx+=1
			tr[p][c]=idx
		p=tr[p][c]
		cnt[p]+=op

def query(s):
	global cnt,tr
	p=0
	for c in s:
		c=ord(c)-ord('0')
		if tr[p][c]==0:
			return 0
		p=tr[p][c]
	return cnt[p]

n=int(input())
a=list(map(int,input().split()))
b=a
a.sort(reverse=True)
sa=[tobase2(x) for x in a]
for s in sa:
	modify(s,1)
for i in range(n):
	tmp=(1<<30)-1
	tmp^=a[i]
	best=tobase2(tmp)
	for j in range(30):
		if not query(cur):