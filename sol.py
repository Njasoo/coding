def factorial(n):
    res = 1
    for i in range(1, n + 1):
        res *= i
    return res

ans = factorial(26) / factorial(10) / factorial(16)
print(ans)

class person:
    __init__(self):
        self.num
        