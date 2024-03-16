import sys

sys.set_int_max_str_digits(999999)
m = int(input())
n = int(input())
l, r = 0, 1
while r**m <= n:
    l = r
    r *= 2
ans = 0
while l <= r:
    mid = (l+r)//2
    if mid**m <= n:
        l = mid+1
        ans = mid
    else:
        r = mid-1
print(ans)
