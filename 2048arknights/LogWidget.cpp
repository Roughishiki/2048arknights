#include "LogWidget.h"
#include "ui_LogWidget.h"
#include<bits/stdc++.h>
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
    m_username = "2212384";
    m_password = "NAOnao040209";
    // 读取json文件
    read_json();
    setWindowIcon(QIcon(":/resources/laiyin.ico"));
    setWindowTitle("登录");
    QMediaPlaylist *musicList = new QMediaPlaylist(this);  //添加音乐列表
    musicList->addMedia(QUrl("qrc:/music/EP1 -Morning Dew.mp3"));  //添加音乐列表
    musicList->addMedia(QUrl("qrc:/music/EP2 -Dormant Craving.mp3"));
    musicList->addMedia(QUrl("qrc:/music/EP3 -The cure.mp3"));



    QMediaPlayer *soundPlayer = new QMediaPlayer(this);  //创建音乐播放器
    soundPlayer->setPlaylist(musicList);  //设置音乐列表
    soundPlayer->setVolume(30);
    soundPlayer->play();
    //以上会使音乐顺序播放



}

LogWidget::~LogWidget()
{


}
void LogWidget::read_json()
{
    //打开文件
    QFile file(QApplication::applicationDirPath()+":/resources/config.json");
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "File open failed!";
    } else {
        qDebug() <<"File open successfully!";
    }
    QJsonDocument jdc(QJsonDocument::fromJson(file.readAll()));
    QJsonObject obj = jdc.object();
    QString save_name_flag=obj.value("SAVE_NAME").toString();
    QString save_password_flag=obj.value("SAVE_PASSWORD").toString();
    message_init(save_name_flag,save_password_flag);
}

//根据json内容决定是否填充输入框
void LogWidget::message_init(QString flag1,QString flag2)
{
    //qDebug() << flag1 << "^^^" << flag2 ;
    if (flag1 == "1")
    {
        ui->edit_name->setText("wuyongwen");
        ui->check_name->setChecked(true);
    }
    if(flag2 == "1")
    {
        ui->edit_pw->setText("wuyongwen");
        ui->check_pw->setChecked(true);
    }
}

// 清理输入栏
void LogWidget::btn_clear_clicked()
{
    ui->edit_pw->clear();
    ui->edit_name->clear();
}

//登录按钮按下后触发的事件
void LogWidget::btn_log_clicked()
{
    QString name = ui->edit_name->text();
    QString password = ui->edit_pw->text();

    if (name == m_username && password == m_password)
    {
        emit(login());
        write_json();
        emit(close_window());
    }
    else
        QMessageBox::information(this, "Warning","Username or Password is wrong !");
}

// 更新json文件
void LogWidget::write_json()
{
    QFile file(QApplication::applicationDirPath()+":/resources/config.json");
    if(!file.open(QIODevice::WriteOnly)) {
        qDebug() << "File open failed!";
    } else {
        qDebug() <<"File open successfully!";
    }
    QJsonObject obj;
    bool flag = ui->check_name->isChecked();
    if(flag == true)
    {
        obj["SAVE_NAME"] = "1";
    }
    else
        obj["SAVE_NAME"] = "0";
    flag = ui->check_pw->isChecked();
    if(flag == true)
    {
        obj["SAVE_PASSWORD"] = "1";
    }
    else
        obj["SAVE_PASSWORD"] = "0";
    QJsonDocument jdoc(obj);
    file.write(jdoc.toJson());
    file.flush();
}

