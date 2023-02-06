import urllib.request as req
import bs4

url = "https://tieba.baidu.com/index.html"

with req.urlopen(url) as response:
    data = response.read().decode("utf-8")

root = bs4.BeautifulSoup(data, "html.parser")

name_of_bas = root.find_all("a", class_ = "title feed-item-link")
for name_of_ba in name_of_bas:
    if name_of_ba != None:
        print(name_of_ba.string)