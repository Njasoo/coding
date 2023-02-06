from random import choice

lottery = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 'a', 'b', 'c', 'd', 'e']
price = []
for i in range(4):
  pick = choice(lottery)
  lottery.remove(pick)
  price.append(pick)
print("If your lottery is same as the following, then you will get the price!")
print(price)