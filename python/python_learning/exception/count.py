filename = 'book.txt'
with open(filename) as f:
  contents = f.read()
print(contents.lower().count("you"))