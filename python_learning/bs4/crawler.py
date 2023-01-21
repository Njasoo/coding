import urllib.request as req

url = "https://www.ptt.cc/bbs/movie/index.html"

# in order not to get ban by the url, we need to do this
# built a request object, with information of request headers
request = req.Request(url, headers = {
  "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:101.0) Gecko/20100101 Firefox/101.0" # just copy it from your browser(use f12)
})

# with req.urlopen(url) as response: # the wedsite will not let us to link
with req.urlopen(request) as response:
  data = response.read().decode("utf-8")
import bs4
root = bs4.BeautifulSoup(data, "html.parser")
# print(root.title) return a tag
"""
print(root.title.string) # text in <title>(text)</title>
"""
"""
titles = root.find("div", class_ = "title") # find tags of div that class == title params: (tag_name, some conditions)
"""
titles = root.find_all("div", class_ = "title")
for title in titles:
  if title.a != None:
    print(title.a.string)