def add(a):
    print("a in add(a):",id(a))
    a+=1

a=0
print(id(a))
add(a)
print(a)