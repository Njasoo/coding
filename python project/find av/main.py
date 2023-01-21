"""
Author: Av盧浮宮
"""

# 從jable.tv上爬到自己想要看的女優的影片番號

import urllib.request as req
import bs4

def getData(url, page_number, actress_name):
  request = req.Request(url, headers = {
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"
  })

  with req.urlopen(request) as response:
    data = response.read().decode("utf-8")

  root = bs4.BeautifulSoup(data, "html.parser")
  titles = root.find_all("h6", class_ = "title")

  filename = "products.txt"
  title_you_want = []
  with open(filename, mode = "a") as file:
    for title in titles:
      if title.a.string != None and title.a.string.find(actress_name) != -1:
        file.write(title.a.string + "\n")
        title_you_want.append(title.a.string)

  if len(title_you_want) == 0:
    print(f"第{int(page_number) - 1}頁: 沒有你想要找的女優")
  else:
    print(f"第{int(page_number) - 1}頁: 找到了")
  
  nextLink = root.find("a", string = page_number)
  return nextLink["href"]

  
filename = "today's movie.txt"

my_url = "https://jable.tv/latest-updates/"
# getData(my_url)

actress_name = input("輸入你想要看的女優的名字, 她的作品將會打印在products.txt中: ").strip()

page = 2
while page < 673:
  if page < 10:
    page_number = "0" + str(page)
  else:
    page_number = str(page)
  my_url = "https://jable.tv" + getData(my_url, page_number, actress_name)
  page += 1
  
"""                   
with open(filename, mode = "w") as file:
  today_movie_titles = getData(my_url)
  for title in today_movie_titles:
    file.write(title.a.string + "\n")
"""
