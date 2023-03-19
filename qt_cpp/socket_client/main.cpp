#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>

#define HOST "127.0.0.1"
#define PORT 20169

int main(int argc, char *argv[])
{
    qDebug("helloworld");
    QTcpSocket * socket = new QTcpSocket();
    socket->connectToHost(QHostAddress(HOST), PORT);
    auto data = QByteArray("query_record");
    socket->write(data);
    socket->waitForReadyRead(-1);
    auto dataread = socket->readAll();
    qDebug()<< "Read" << dataread;
    socket->close();
}
