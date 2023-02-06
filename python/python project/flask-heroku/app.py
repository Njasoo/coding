from flask import Flask

app = Flask(__name__) # __name__ 代表目前执行的模组 主程式的意思

@app.route("/") # 函数的装饰 (decorator) 以函数为基础, 提供附加的功能 斜线代表根目录
def home():
    return "Hello Flask 2"

@app.route("/test")
def test():
    return "This is Test"

if __name__ == "__main__":
    app.run() # 启动伺服器