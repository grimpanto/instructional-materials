import socket, struct, time, datetime
PORT = 8037
# PORT = 37  # if using a real one, e.g. time.nist.gov
TIME1970 = 2208988800  # sec: 1.1.1900 - 1.1.1979

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect(("", PORT))
# sock.connect(("time.nist.gov", PORT))

t = sock.recv(4)

t = struct.unpack("!I", t)[0] - TIME1970

sock.close()

print(datetime.datetime.fromtimestamp(t))
