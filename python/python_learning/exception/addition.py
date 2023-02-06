print("input two numbers, and then I'll add them together")
while True:
  try:
    first_number = int(input("input first number"))
    second_number = int(input("input second number"))
  except ValueError:
    print("things that you input are not numbers")
  else:
    print(first_number + second_number)