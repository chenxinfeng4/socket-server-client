#include <QCoreApplication>
#include "tcpserver.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TcpServer *tcpServer = new TcpServer();
    tcpServer->on_socket_activate(true);
    return a.exec();
}
