import socketserver
HOST, PORT = "127.0.0.1",20169

class MyTCPHandler(socketserver.BaseRequestHandler):
    """
    The request handler class for our server.

    It is instantiated once per connection to the server, and must
    override the handle() method to implement communication to the
    client.
    """

    def handle(self):
        # self.request is the TCP socket connected to the client

        print("conn is :",self.request) # conn
        print("addr is :",self.client_address) # addr
 
        while True:
            try:
                #收消息
                data = self.request.recv(1024)
                if not data:break
                print("收到客户端的消息是",data.decode("utf-8"))
                #发消息
                self.request.sendall(data.upper())
            except Exception as e:
                print(e)

        print('Closed a request')

if __name__ == "__main__":
    # Create the server, binding to localhost on port 9999
    with socketserver.TCPServer((HOST, PORT), MyTCPHandler) as server:
        # Activate the server; this will keep running until you
        # interrupt the program with Ctrl-C
        server.serve_forever()
