from numpy import *

m = [0, 10, 20, 30, 40, 50]
T2 = [14.427, 19.242, 24.221, 29.247, 34.463, 39.874]


miti2 = 0
ti2 = 0
mi = 0
for i in range(0, 6):
    miti2 += m[i] * T2[i]
    ti2 += T2[i]
    mi += m[i]

mi2 = 0

for i in range(0, 6):
    mi2 += m[i] ** 2

fenzi = miti2 - (1 / 6) * mi * ti2
fenmu = mi2 - (1 / 6) * mi ** 2

k = fenzi / fenmu

print(k)

T2_bar = mean(T2)
m_bar = mean(m)

# print(f"T2_bar: {T2_bar}")
# print(f"k * m_bar: {k * m_bar}")
m0 = T2_bar - m_bar * k
print(m0)