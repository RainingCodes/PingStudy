import requests

url = "http://suninatas.com/challenge/web07/web07.asp"
url2 = "http://suninatas.com/challenge/web07/web07_1.asp"

s = requests.Session()

res1 = s.get(url)
res2 = s.post(url2)
print(res2.text)
