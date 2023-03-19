# Socket server and client template
---
It's a simple template of echo server for socket communication. It contains `python`, `c++`, `shell` languages across `linux`, `windows` platforms. 

## How to use
---
### Python
```shell
$ python socket_server_client/python/socket_server.py
$ python socket_server_client/python/socket_client.py
```

### C++ linux
```shell
$ cd socket_server_client/linux_cpp
$ g++ -Wall socket_server.cpp -o socket_server
$ g++ -Wall socket_client.cpp -o socket_client
$ ./socket_server
$ ./socket_client
```

### C++ windows QT
After built on QT5
```
> socket_server_client/qt_cpp/socket_server/socket_server.exe
> socket_server_client/qt_cpp/socket_client/socket_client.exe
```

### Shell
```
$ bash socket_server_client/shell/socket_server_socat.sh
$ bash socket_server_client/shell/socket_client_nc.sh
```