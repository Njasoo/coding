import urllib.request as req
import bs4

url = "https://covid19map.ssm.gov.mo/index.html"

request = req.Request(url, headers = {
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36"
})

with req.urlopen(request) as response:
    data = response.read().decode("utf-8")

root = bs4.BeautifulSoup(data, "html.parser")

# print(root)

uls = root.find_all("ul")
print(uls)