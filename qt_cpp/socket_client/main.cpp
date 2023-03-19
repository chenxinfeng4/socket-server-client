#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>

int main(int argc, char *argv[])
{
    qDebug("helloworld");
    QTcpSocket * socket = new QTcpSocket();
    socket->connectToHost(QHostAddress("127.0.0.1"), 20169);
    auto data = QByteArray("Message!");
    socket->write(data);
    socket->waitForReadyRead(-1);
    auto dataread = socket->readAll();
    qDebug()<< "Read" << dataread;
    socket->close();
}
