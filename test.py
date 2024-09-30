N=[10, 100, 1000]
U=[300*2**10, 700*2**10, 2*2**20]
F=20*2**30
u_s=30*2**20
d=2*2**20

def calc1_1(n):
    return n * F / u_s

def calc1_2():
    return F / d

def calc2_1():
    return F / u

def calc2_2():
    return calc1_2()

def calc2_3(n, u):
    return n * F / (u_s + n * u)

for n in N:
    for u in U:
        T_cs = max([calc1_1(n), calc1_2()])
        T_p2p = max([calc2_1(), calc2_2(), calc2_3(n, u)])
        print(f"n = {n}, u = {u}")
        print(f"T_cs = {T_cs}, T_p2p = {T_p2p}")
        print()