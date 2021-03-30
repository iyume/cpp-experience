import requests

def getHTML(url, datas={}, headers={}):
    response = requests.post(url=url, datas=datas, headers=headers)
    return response.content.decode()

def getCookie(url):
    response = requests.get(url)
    return response.content.decode()

url = "http://10-34-67-241.webvpn.cust.edu.cn:8118/exp/index.jsp?assignID=60"

print(getCookie(url))