#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QDateTime>
#include <QMessageBox>
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

    QSound *messageSound;
    QSound *connectSound;
private slots:
    void on_connectBtn_clicked();   //连接按钮

    void on_sendBtn_clicked();      //发送按钮

    void readMessage();         //接收信息

    void disconnectSlot();          //断开连接槽函数

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
    bool connectState;  //客户端连接状态

};

#endif // WIDGET_H
