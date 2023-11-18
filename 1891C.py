if __name__ == "__main__":
    tt = int(input())
    a = list(map(int, input().split()))
    a.sort()
    l = 0, r = len(a) - 1
    x = 0
    while l < r:
           