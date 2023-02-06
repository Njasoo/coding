import urllib.request as req
import bs4

# 每天都要更改网址
start_url = "http://www.macaodaily.com/html/2022-07/02/node_2.htm"
prefix = "http://www.macaodaily.com/html/2022-07/02/"

filename = "today_news.txt"

# 清空文件
with open(filename, mode = "r+", encoding = "utf-8") as f:
    f.truncate(0)

def get_page(url):
    request = req.Request(url, headers = {
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"
    })
    with req.urlopen(request) as response:
        data = response.read().decode("utf-8")

    page = bs4.BeautifulSoup(data, "html.parser")
    return page

start_page = get_page(start_url)
pageLinks = start_page.find_all("a", attrs = {"id": "pageLink"})

# 抓取右边的所有链接, 一个一个进去, 获取页面资料, 然后把整个页面的标题全部打印出来
for pageLink in pageLinks:
    next_url = prefix + pageLink.attrs.get("href")
    next_page = get_page(next_url)
    titles = next_page.find_all("div", attrs = {"style": "display:inline"})
    with open(filename, mode = "a", encoding = "utf-8") as f:
        for title in titles:
            # parent 上一级tag标签
            f.write(title.string + " " + prefix + title.parent.attrs.get("href") + "\n")