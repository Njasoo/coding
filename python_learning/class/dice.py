from random import randint

class Die:
  def __init__(self, sides = 6):
    self.sides = sides

  def roll_die(self):
    print(randint(1, self.sides))

dice6 = Die(6)
cnt = 1
for i in range(10):
  print(f"dice6 take {cnt}")
  cnt += 1
  dice6.roll_die()
cnt = 1
dice10 = Die(10)
dice20 = Die(20)
for i in range(10):
  print(f"dice10 take {cnt}")
  cnt += 1
  dice10.roll_die()
cnt = 1
for i in range(10):
  print(f"dice20 take {cnt}")
  cnt += 1
  dice20.roll_die()