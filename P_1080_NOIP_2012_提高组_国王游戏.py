from functools import cmp_to_key


class Node:
    def __init__(self, a, b):
        self.a = a
        self.b = b


def mycmp(i, j):
    if i.a*i.b == j.a*j.b:
        return i.b-j.b
    return i.a*i.b-j.a*j.b


n = int(input())
t = []
a, b = map(int, input().split())
for i in range(n):
    ta, tb = map(int, input().split())
    t.append(Node(ta, tb))

t.sort(key=cmp_to_key(mycmp))
prel = a
ans = 0
for i in range(n):
    ans = max(ans, prel//t[i].b)
    prel *= t[i].a
print(ans)
