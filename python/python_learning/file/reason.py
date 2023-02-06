file_name = "reason.txt"
while True:
  reason = input("Why do you love programming?\n")
  with open(file_name, 'a') as obj:
    obj.write(f"{reason}\n")