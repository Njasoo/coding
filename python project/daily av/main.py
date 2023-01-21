import urllib.request as req
import bs4

# 要進入的網址
url = "https://jable.tv"

# 僞裝用戶的文件
request = req.Request(url, headers = {
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"
})

# 開始對api發送請求
with req.urlopen(request) as response:
    data = response.read().decode("utf-8")

# 接收到的html文件
root = bs4.BeautifulSoup(data, "html.parser")
titles = root.find_all("h6", class_ = "title")

for title in titles:
    if title.a != None:
        print(title.a.string)