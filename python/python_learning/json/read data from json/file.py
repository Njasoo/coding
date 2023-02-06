import json

with open('config.json', mode = 'r') as file:
  data = json.load(file)
# because data is a dictionary
print(data)
data["name"] = "New Name"
with open('config.json', mode = 'w') as file:
  json.dump(data, file)

