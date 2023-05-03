#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonDocument>
#include<QPaintEvent>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include<QPainter>
#include <QByteArray>


namespace Ui {
class LogWidget;
}


class LogWidget : public QWidget
{
    Q_OBJECT

public:

    explicit LogWidget(QWidget *parent = nullptr);
    ~LogWidget();

    void read_json(); //读json
    void write_json();//写json
    void message_init(QString flag1,QString flag2);//根据json内容决定是否填充输入框


signals:
    void login(); //登录主界面信号
    void close_window();  //关闭登录界面信号


public slots:
    void btn_clear_clicked();  //重置按钮按下后触发的事件
    void btn_log_clicked();  //登录按钮按下后触发的事件


private:
    Ui::LogWidget *ui;
    QString m_username;
    QString m_password;


};


#endif //LOGWIDGET_H
