file_name = "guest_book.txt"
while True:
  name = input("input your name: ")
  print(f"Hello, {name}!\n")
  with open(file_name, 'a') as obj:
    obj.write(f"{name}\n")