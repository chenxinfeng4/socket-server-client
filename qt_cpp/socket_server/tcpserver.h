#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>


class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    bool tcpcmd_start_record(char *outmsg);
    bool tcpcmd_stop_record(char *outmsg);
    int tcpcmd_query_record(char *outmsg);

signals:
    void tell_socket_port(QString port);
    void recordButtonClick();
    void stopButtonClick();


public slots:
    void on_socket_activate(bool activate);

protected:
    void incomingConnection(qintptr socketDescriptor);
};


namespace TCPSERVER_PRIVATE{
    class MyThread : public QThread
    {
        Q_OBJECT
    public:
        explicit MyThread(qintptr ID, TcpServer *tcpserver, QObject *parent = 0);
        void run();

    signals:
        void error(QTcpSocket::SocketError socketerror);

    public slots:
        void readyRead();
        void disconnected();

    private:
        TcpServer *tcpServer;
        QTcpSocket *socket;
        qintptr socketDescriptor;
    };
}

#endif // TCPSERVER_H
