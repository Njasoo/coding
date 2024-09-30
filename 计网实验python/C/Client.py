import socket


def main():
    # 初始化Winsock（在Python中不需要，因为socket库已经封装了这些细节）

    # 创建Socket
    clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Socket create Ok!")

    # 设置客户端的IP和端口（在Python中通常不需要显式绑定客户端Socket）
    # 如果需要，可以使用clientSocket.bind(('localhost', 0))来绑定到任意端口

    # 设置服务器的IP和端口
    server_address = ('127.0.0.1', 5050)

    # 连接到服务器
    try:
        clientSocket.connect(server_address)
        print("Connect to server ok!")
    except socket.error as e:
        print(f"Connect to server error: {e}")
        return

    # 主循环，发送数据到服务器
    while True:
        input_message = input("\nPlease input your message: ")
        if input_message == "quit":
            break

        # 发送数据到服务器
        try:
            clientSocket.sendall(input_message.encode('utf-8'))
        except socket.error as e:
            print(f"Send to server failed: {e}")
            break

    # 关闭Socket
    clientSocket.close()


if __name__ == "__main__":
    main()
