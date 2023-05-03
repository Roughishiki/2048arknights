#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_log = new LogWidget;
        // 调用登录窗口的show()函数显示登录界面
        m_log->show();

        // 建立信号槽，到接收到登录界面发来的login()信号后，调用主窗口的show()函数。
        connect(m_log,SIGNAL(login()),this,SLOT(show()));

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            s[i][j]=0;

        }

    }
    button=new QPushButton("开始游戏",this);
    button->setGeometry(80,400,200,50);
    //随机函数
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
connect(button,SIGNAL(clicked()),this,SLOT(slotStart()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
QPainter p(this);
QPen pen;
pen.setWidth(5);
p.setBrush(Qt::blue);
p.setFont(QFont("魂心",20,700,false));
QString strscore;
p.drawText(QPoint(20,60),"分数："+QString::number(score));
//画格子
for(int i=0;i<4;i++)
{
   for(int j=0;j<4;j++)
   {
       p.setPen(Qt::transparent);
       if(s[i][j]==0)
       {
           p.setBrush(QBrush(QColor(255,243,10,70)));
       p.drawRect(i*60+40,j*60+120,55,55);
       }
       else if(s[i][j]==2)
       {
           p.setPen(pen);
           p.drawPixmap(0,180,80,80,QPixmap("../resources/level1"));
       }

       }
   }
setWindowIcon(QIcon(":/resources/axqsx-7wyta-001"));


}

void MainWindow::keyPressEvent(QKeyEvent *event)
{



}
