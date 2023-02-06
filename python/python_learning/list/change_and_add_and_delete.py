'''
motorcycles = ["honda", "yamaha", "suzuki"]
print(motorcycles)

motorcycles[0] = "ducati"
print(motorcycles)

motorcycles.append("ducati")
print(motorcycles)

motorcycles = ["honda", "yamaha", "suzuki"]
motorcycles.insert(0, "ducati")

print(motorcycles)

del motorcycles[0]
print(motorcycles)
'''

motorcycles = ["honda", "yamaha", "suzuki"]

popped_motorcycles = motorcycles.pop()
print(motorcycles)
print(popped_motorcycles)

motorcycles.remove("honda")
print(motorcycles)
