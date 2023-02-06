import requests

url = "https://api.github.com/search/repositories?q=language:python&sort=stars"
headers = {"Accept": "application/vnd.github.v3+json"}
r = requests.get(url, headers = headers)
print(f"Status code: {r.status_code}")
reponse_dict = r.json()

print(reponse_dict.keys())