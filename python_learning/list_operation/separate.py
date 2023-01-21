a = list(range(0, 10))

print(a[0:2])

print(a[1:3])

print(a[:4])

print(a[2:])

print(a[-3:])

b = a[:]
print(b)

for x in a[:3]:
  print(x)