#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>

namespace Ui {
class LogWidget;
}


class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = nullptr);
    ~LogWidget();

signals:
    void login(); //登录主界面信号
    void close_window(); //关闭登录界面信号
public slots:
    void btn_clear_clicked(); //重置按钮按下后触发的事件
    void btn_log_clicked(); //登录按钮按下后触发的事件

private:
    Ui::LogWidget *ui;
    QString m_username;  // 自己设定的账号
      QString m_password;  // 自己设定的密码
};

#endif //LOGWIDGET_H
