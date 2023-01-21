def count_words(file_name):  
  try:
    with open(file_name, encoding = 'utf-8') as f:
      contents = f.read()
  except FileNotFoundError:
    pass
  else:
    words = contents.split()
    num_words = len(words)
    print(f"The file {file_name} has about {num_words} words.")

filenames = ['alice.txt', 'a', 'b', 'c']
for file_name in filenames:
  count_words(file_name)