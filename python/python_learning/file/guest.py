file_name = "guest.txt"
name = input("input your name: ")
with open(file_name, 'a') as obj:
  obj.write(f"{name}\n")