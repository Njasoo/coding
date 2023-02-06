class User:
  def __init__(self, name, age, password):
    self.name = name.strip().title()
    self.age = age.strip()
    self.password = password.strip()

  def printInfo(self):
    print(f"\tname: {self.name.title()}")
    print(f"\tage: {self.age}")
