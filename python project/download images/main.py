import requests
IMAGE_URL = "https://www.preface.ai/blog/wp-content/uploads/2021/05/photo-1610563166150-b34df4f3bcd6-768x575.jpeg"

images = requests.get(IMAGE_URL)
# 在vscode这里建议使用绝对路径
filename = "D:/coding/python project/download images/images/test.jpeg"
with open(filename, mode = "wb") as f:
    f.write(images.content)