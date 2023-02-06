import urllib.request as req
import bs4
import requests

my_url = "https://jable.tv"

def getData(url):
  request = req.Request(url, headers = {
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"
  })
  with req.urlopen(request) as response:
    data = response.read().decode("utf-8")

  root = bs4.BeautifulSoup(data, "html.parser")
  return root

"""
debug_file_name = "debug.txt"
with open(debug_file_name, "w") as f:
  f.write(str(root))
"""

root = getData(my_url)

imgs = root.find_all("img", class_ = "lazyload")
print(len(imgs))

number = 0
for img in imgs:
  imageLink = img.attrs.get("data-src")
  print(imageLink)
  image = requests.get(imageLink)
  if number < 10:
    file_number = "0" + str(number)
  else:
    file_number = str(number)
  filename = "D:/coding/python project/av cover images/images/" + file_number + ".jpg"
  number += 1
  with open(filename, mode = "wb") as f:
    f.write(image.content)