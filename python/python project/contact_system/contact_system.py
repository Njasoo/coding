from user import User

def signUp():
  name = input("input name: ")
  for user in users:
    if user.name == name.strip().title():
      print("user has already exist")
      return None
  age = input("input age: ")
  if (int(age) < 18):
    print("you are too young")
    return None
  password = input("input password: ")
  new_user = User(name, age, password)
  users.append(new_user)

def logIn():
  finded = False
  name = input("input name: ")
  for user in users:
    if user.name == name.strip().title():
      now_user = user
      finded = True
  if finded == False:
    print("user doesn't exist")
  else:
    password = input("input password: ")
    if password == now_user.password:
      now_user.printInfo()
    else:
      print("password incorrect")

def deleteUser():
  name = input("input name: ")
  finded = False
  for user in users:
    if user.name == name.strip().title():
      users.remove(user)
      finded = True
  if finded == False:
    print("user doesn't exist")
  else:
    print("deleted successfully")  

users = []
while True:
  print("1. sign up")
  print("2. log in")
  print("3. delete user")
  opt = int(input())
  if opt == 1:
    signUp()
  elif opt == 2:
    logIn()
  elif opt == 3:
    deleteUser()
  else:
    print("invaild number")
