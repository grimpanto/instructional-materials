import socket, struct, time
PORT = 8037
TIME1970 = 2208988800  # sec: 1.1.1900 - 1.1.1979
serversock = socket.socket(socket.AF_INET,
                           socket.SOCK_STREAM)
serversock.bind(("", PORT))
serversock.listen(3)  # size of backlog queue

while True:
    clientsock, clientaddr = serversock.accept()
    print("Verbindung von:", clientaddr)
    t = int(time.time()) + TIME1970

    # pack into 4 byte integer network-byte-order (!)
    t = struct.pack("!I", t)

    clientsock.send(t)
    clientsock.close()
