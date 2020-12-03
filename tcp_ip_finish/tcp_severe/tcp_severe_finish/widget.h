#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QList>
#include <QAbstractSocket>
#include <QMessageBox>
#include <QStringList>
#include <QDateTime>
#include <QNetworkInterface>
#include <QMediaPlayer>
#include <QSound>
#include <QIcon>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QMediaPlayer *startSound;  //创建一个音乐播放器
    QSound *connectSound;
    QSound *messSound;


    void enumAllIp();         //存储本机所有可用的ipv4地址
private slots:
    void newConnectSlot();      //客户端连接后处理
    void disConnectSlot();      //客户端断开连接后处理
    void readMessage();         //接收信息的槽函数



    void on_listenBtn_clicked();      //监听槽函数

    void on_sendBtn_clicked();       //发送信息槽函数

private:
    Ui::Widget *ui;
    QTcpServer *severe;   //服务端
    QList <QTcpSocket*> clintList_sock;   //多个客户端的套接字列表
    QTcpSocket *clintSock;


};

#endif // WIDGET_H
