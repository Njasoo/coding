file_name = 'pi_digits.txt'
with open(file_name) as obj:
  lines = obj.readlines()
pi_string = ''
for line in lines:
  pi_string += line.rstrip()
print(pi_string)
print(len(pi_string))