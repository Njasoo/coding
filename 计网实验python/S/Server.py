import socket
import select


def main():
    # 创建socket
    srv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 设置端口和IP
    srv_socket.bind(('0.0.0.0', 5050))

    # 监听连接
    srv_socket.listen(5)
    print("Socket listen Ok!")

    # 设置非阻塞模式
    srv_socket.setblocking(False)

    client_sockets = []
    first_connection = True

    while True:
        # 使用select监控socket
        read_sockets = [srv_socket] + client_sockets
        write_sockets = client_sockets

        # 等待连接或数据
        readable, writable, exceptional = select.select(
            read_sockets, write_sockets, [])

        for s in readable:
            # 如果srv_socket收到连接请求
            if s is srv_socket:
                session_socket, client_address = srv_socket.accept()
                print("Socket listen one client request!")

                # 设置会话socket为非阻塞模式
                session_socket.setblocking(False)
                client_sockets.append(session_socket)

            else:
                # 接收来自客户端的数据
                try:
                    data = s.recv(256)
                    if data:
                        print(
                            f"Received {len(data)} bytes from client: {data.decode()}")
                    else:
                        print("Client leaving ...")
                        client_sockets.remove(s)
                        s.close()
                except ConnectionResetError:
                    print("Client disconnected unexpectedly.")
                    client_sockets.remove(s)
                    s.close()


if __name__ == "__main__":
    main()
