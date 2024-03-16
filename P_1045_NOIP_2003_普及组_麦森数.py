from math import *


def power(u, v):
    res = 1
    while v != 0:
        if v % 2 == 1:
            res *= u
        u *= u
        v //= 2
    return res


p = int(input())
ans = power(2, p)-1
ans1 = int(log10(ans))+1
print(ans1)
cnt = 0
ans %= power(10, 500)
ans = str(ans)
for i in range(500-len(ans)):
    print(0, end='')
    cnt += 1
    if cnt % 50 == 0:
        print()
for ch in ans:
    print(ch, end='')
    cnt += 1
    if cnt % 50 == 0:
        print()
