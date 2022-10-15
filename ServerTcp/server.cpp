#include "server.h"

Server::Server()
{
    if(this->listen(QHostAddress::Any,2222))
    {
        qDebug() << "Start Server!";
    }
    else{
        qDebug() << "Error: Server is not started!";
    }
    nextBlockSize = 0;
}
void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "New Client connected" << socketDescriptor;
}
void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    socket = qobject_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_12);
    if(in.status() == QDataStream::Ok)
    {
        for(;;)
        {
            if(nextBlockSize==0)
            {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString str;
            QTime time;
            in >> time >> str;
            nextBlockSize = 0;
            qDebug() << str;
            SendToClient(str);
            break;
        }
    }
    else{
        qDebug() << "DataStream error";
    }
}
void Server::SendToClient(QString str)
{
    Data.clear();//ОБЯЗАТЕЛЬНО НАДО ЧИСТИТЬ ПЕРЕД ИСПОЛЬЗОВАНИЕМ
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    for(int i=0;i<Sockets.size(); i++)
    {
        Sockets[i]->write(Data);
    }
}
