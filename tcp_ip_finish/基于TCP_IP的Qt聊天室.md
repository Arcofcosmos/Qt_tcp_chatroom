# 基于TCP/IP的Qt聊天室

## 成果展示

<img src="C:\Users\TuZhou\Desktop\聊天室.gif" style="zoom: 100%" />

环境：Qt Creator5.12

## 服务端

可使用电脑的telnet客户端进行测试。

ip地址：0.0.0.0代表任何Ip地址，127.0.0.1代表本机网卡的ip地址。

端口：一定为正数，使用的端口不要和本机正在使用的端口重复了。最好使用5555, 8888这样的端口。



cmd命令：

1. netstat -ano     //查看本机所有地址及端口的状态
2. telnet 127.0.0.1 8888    //开启telnet客户端连接该ip地址的8888端口，并可以发送信息





### 实现流程

1. 使用ui设计界面
2. 运行界面就创建服务端，并初始化本机所有可用的ipv4地址到列表框中，同时准备连接信号newconnection及其槽函数newconnectionSlot()
3. 监听按钮连接槽函数，获取当前端口和ip地址，如果正在监听则关闭服务端，否则开始监听，监听失败出现错误消息框
4. 若有客户端连接，则获取其套接字信息，添加到客户端套接字列表中，在listwidget中显示连接的地址和端口信息，此时准备好读取信息的信号readyread和断开连接的信号disconnected以及对应的槽函数
5. 接收信息时，服务端收到信息，给其他客户端发送同样的信息，信息要含有当前的时间，服务端收到一个客户端的信息就break
6. 断开连接的槽函数中，服务端收到包含时间的clint close的信息
7. 发送按钮控制发送槽函数，给所有客户端发送信息，同时在自己的接收消息的消息框中显示自己发送的信息





### 代码

.pro文件：`QT       += core gui network`  

需要network库才可使用网络通信的接口。



### 库：

#### QTcpSocket          //tcp套接字类

1. `newConnection         //信号。当有新连接进来时被发送`

2. `QTcpSocket.peerAdress()   //返回套接字方的地址`

3. `QTcpSocket.peerPort()   //返回套接字方的端口`

4. `readyRead           //信号，有数据传送过来时发送`

5. `disconnected           //信号，当套接字断开连接时发送`

6. `QTcpSocket.readAll()    //一次读取所有字节`

7. `QTcpSocket.write()    //通过套接字发送信息，要将字符串转换成utf8格式`

8. `isreadable()         //检查当前套接字的发送信息是否可读，可返回true，否则反之`

9. `iswriteable()                   //检查当前套接字是够可以发送信息，可则返回true,否则反之`

   

#### QHostAddress     //主机地址类，提供主机ip地址

1. `QHostAddress.protocol()     //返回该地址的协议族`
2. `QHostAddress.isNull()          //检查该地址是否为空`
3. `QHostAddress(QString address)   //地址字符串类型转换为主机ip`



#### QNetworkInterface     //提供主机的ip地址列表

1. `allAddresses()     //该函数返回主机发现的所有Ip地址，使用QList<QHostAdress>接收`



#### QList     //列表

1. `QList.size()    //长度`
2. `QList.count()     //长度`
3. `QList.at(index)      //返回列表索引Index对应的项`
4. `QList.at(index).protocol()   //返回该项地址的协议族`



#### QStringList   //字符串列表

1. `QStringList.clear()      //清空字符串列表所有项`
2. `QStringList.append(string)   //往字符串列表中添加字符串`
3. 



#### QAbstractSocket   //套接字类型的基类

1. `NetworkLayerProtocol protocol   //创建网络层协议族对象`

2. `QAbstractSocket::IPv4Protocol     //ipv4协议族`

   





#### QComboBox    //列表框，可以当做QEditline输入

1. `QComboBox.addItems(List)    //添加列表`

2. `QCOmboBox.currentText()      //返回列表框当前的文本`





#### QTcpSevere         //tcp服务端类

1. `QTcpSevere.isListening()      //检查当前服务端是否在监听，是返回true，否则返回false`
2. `QTcpSevere.listen(QHostAddress, port)   //开始监听，参数1为QHostAddress类型，要将地址字符串转为该类型，监听成功返回true,否则返回false`
3. `QTcpSevere.errorString()        //服务端异常返回错误原因字符串`
4. `QTcpSevere.nextPendingConnection()    //返回连接方的套接字对象`
5. `incomingConnection(qintptr handle)   //当有新连接时调用该虚函数，handle为连接者的描述信息`
6. `QTcpsocket->setSocketDescriptor(handle);  //将连接者的描述信息传给套接字`



#### QMessageBox   //消息盒子

1. `QMessageBox::warning(QWidget *parent, const QString &title, const QString &text, int button0, int button1, int button2 = 0)`



#### QByteArray   //字节流数组，存储收发的字节

1. `QByteArray.data()    //将字节转换成字符串`



#### QDateTime     //日期时间

1. `currentDateTime().toString("")      //获取当前日期时间`





构造函数中：`listen(QHostAddress::Any, 8888)     //开启监听本机任意ip地址的8888端口`

虚函数重写：`void incomingConnection(qintptr handle)   //当有新连接时自动调用该槽函数，handle为连接方的描述信息`

创建套接字：`QTcpSocket *sock    //未使用该套接字时不能为其分配内存，否则程序异常`

`sock->peerAddress().toString()    //获取对方的ip地址`

当从客户端传入信息时，sock会发送读取信号，需要连接读取槽函数才可读取，否则只有连接，无法读取：

`connect(sock, &QIODevice::readyRead, this, &severe::receiveMessage);   //有数据连接到sock时传入信号`

severe.h: 

`void  giveMess(QString, int);     //传递信息的信号,int代表信息为消息还是提醒日志，1为消息，2为日志`



### ui设计：

1. Qplaintextedit       //多行文本编辑器，用于发送信息
2. Qlistwidget            //列表框，显示连接状态
3. QTextBrowser           //富文本浏览器，显示收到的消息,append(string)接收
4. Qcombobox           //列表框，可当做Qline edit输入，用来存放地址
5. Qpushbutton       //按钮
6. label            //标签
7. QLineEdit      //输入框 
8. 界面设计好要先编译才可正常使用控件——ctrl+b



## 客户端

### 实现流程：

1. 设计客户端的ui界面，与服务端类似
2. 创建套接字以及连接bool变量信息显示连接状态
3. 运行程序即创建套接字，准备套接字断开disconnected信号及信息接收readyread信号的连接
4. 连接按钮槽函数控制与服务端的连接，获取界面当前的ip地址及端口号，连接状态未连接则连接服务端，连接上了显示连接信息，未连接上显示连接错误信息；连接状态连接上了则关闭套接字，此时会发送disconnected信号
5. disconnected槽函数触发打印套接字关闭信息
6. 接收信息槽函数在接收信息富文本框中显示收到的信息，并包含时间
7. 发送按钮槽函数若套接字打开可用则给服务端发送信息，并在自己的富文本框中显示自己发送的信息，并包含时间



### 库

#### QTcpSocket          //tcp套接字类

1. `QTcpSocket.connectToHost(qstring address, quint16 port)         //客户端连接到主机`
2. `QTcpSocket.waitForConnected()          //等待30000毫秒套接字连接，如果连接上了返回true，如果时间到了没连上返回false`
3. `QTcpSocket.errorString()         //返回套接字错误信息`
4. `QTcpSocket.isOpen()      //检查套接字是否打开`
5. `QTcpSocket.isValid()          //检查套接字是否可用`















