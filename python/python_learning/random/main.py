import random
"""
data = random.choice([1, 4, 6, 632, 123,5])
"""
# data = random.sample([1, 12, 14, 5123], 2) # return a list  params: (list, number of choices)
# print(data)

"""
data = [1, 2, 3, 4]
random.shuffle(data)
print(data)
"""
# data = random.random() # random number in (0, 1)
"""
data = random.uniform(60, 100) # same as above
print(data)
"""
# most of the time, the number you get is in [90, 110]
data = random.normalvariate(100, 10) # prams: (average, standard deviation)
print(data)