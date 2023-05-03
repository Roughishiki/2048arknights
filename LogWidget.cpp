#include "LogWidget.h"
#include "ui_LogWidget.h"
#include<QMessageBox>


LogWidget::~LogWidget()
{

}


    LogWidget::LogWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::LogWidget)
    {
        ui->setupUi(this);
        // connect
        // 触发重置按钮的信号槽连接
        connect(ui->btn_clear,SIGNAL(clicked()),this,SLOT(btn_clear_clicked()));
        // 触发登录按钮的信号槽连接
        connect(ui->btn_log,SIGNAL(clicked()),this,SLOT(btn_log_clicked()));
        // 发出信号后关闭登录窗口的信号槽连接
        connect(this,SIGNAL(close_window()),this,SLOT(close()));
        ui->edit_pw->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点
        m_username = "wuyongwen";
        m_password = "wuyongwen";
       }


    void LogWidget::btn_log_clicked()
    {
        // 从输入框获取账号
        QString name = ui->edit_name->text();
        // 从输入框获取密码
        QString password = ui->edit_pw->text();

        //账号和密码匹配正确
        if (name == m_username && password == m_password)
        {
            emit(login());
            emit(close_window());
        }
        else // 账号或密码错误
            QMessageBox::information(this, "Warning","Username or Password is wrong !");
    }
void LogWidget::btn_clear_clicked()
{




}
