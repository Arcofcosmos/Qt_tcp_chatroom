/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *listWidget;
    QComboBox *ipBox;
    QLineEdit *leport;
    QPushButton *listenBtn;
    QTextBrowser *textReceive;
    QPlainTextEdit *textSend;
    QPushButton *sendBtn;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(563, 404);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(400, 60, 151, 321));
        ipBox = new QComboBox(Widget);
        ipBox->setObjectName(QString::fromUtf8("ipBox"));
        ipBox->setGeometry(QRect(110, 20, 131, 22));
        leport = new QLineEdit(Widget);
        leport->setObjectName(QString::fromUtf8("leport"));
        leport->setGeometry(QRect(360, 20, 81, 21));
        listenBtn = new QPushButton(Widget);
        listenBtn->setObjectName(QString::fromUtf8("listenBtn"));
        listenBtn->setGeometry(QRect(460, 20, 81, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(6, 163, 220, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        listenBtn->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        listenBtn->setFont(font);
        textReceive = new QTextBrowser(Widget);
        textReceive->setObjectName(QString::fromUtf8("textReceive"));
        textReceive->setGeometry(QRect(20, 60, 371, 281));
        textReceive->setFont(font);
        textSend = new QPlainTextEdit(Widget);
        textSend->setObjectName(QString::fromUtf8("textSend"));
        textSend->setGeometry(QRect(20, 360, 281, 31));
        sendBtn = new QPushButton(Widget);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(310, 360, 81, 28));
        sendBtn->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 81, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 20, 81, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\346\264\262\346\264\262TCP\346\234\215\345\212\241\347\253\257", nullptr));
#ifndef QT_NO_TOOLTIP
        leport->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        listenBtn->setText(QApplication::translate("Widget", "\347\233\221\345\220\254", nullptr));
        sendBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\234\254\345\234\260IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Widget", "\346\234\254\345\234\260\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
