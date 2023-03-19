#%% testsocket.py
import socket
import time
# %% create connection
tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serve_ip = 'localhost'
serve_port = 20169
tcp_socket.connect((serve_ip, serve_port))

def send_read(send_data):
    send_data_byte = send_data.encode("utf-8")
    tcp_socket.send(send_data_byte)

    from_server_msg = tcp_socket.recv(1024)
    print(from_server_msg.decode("utf-8"))

# %% Supported commands
cmds = ['query_record', 'start_record', 'stop_record']

for send_data in cmds:
    send_read(send_data)
    time.sleep(5)

tcp_socket.close()
