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
    button->setGeometry(60,400,200,50);
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
           p.setBrush(QBrush(QColor(181,180,180,70)));
           p.drawRect(i*60+40,j*60+120,55,55);
       }
       else if(s[i][j]==2)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level2.png"));
       }
       else if(s[i][j]==4)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level4.png"));
       }
       else if(s[i][j]==8)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level8.png"));
       }
       else if(s[i][j]==16)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level16.png"));
       }
       else if(s[i][j]==32)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level32.png"));
       }
       else if(s[i][j]==64)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level64.png"));
       }
       else if(s[i][j]==128)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level128.png"));
       }
       else if(s[i][j]==256)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level256.png"));
       }
       else if(s[i][j]==512)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level512.png"));
       }
       else if(s[i][j]==1024)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level.png"));
       }
       else if(s[i][j]==2048)
       {
           p.setPen(pen);
           p.drawPixmap(i*60+40,j*60+120,55,55,QPixmap(":/resources/level2048.png"));
       }
       else
       {
           p.setBrush(Qt::darkBlue);
           p.drawRect(i*60+40,j*60+120,55,55);
           p.setPen(Qt::black);
           p.setFont(QFont("微软雅黑",10,700,false));
           p.drawText(QRect(i*60+40,j*60+120,55,55),QString::number(s[i][j]),QTextOption(Qt::AlignCenter));

       }


       }
   }
setWindowIcon(QIcon(":/resources/axqsx-7wyta-001"));


}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!state)
  {
    return;

  }
    switch(event->key())
    {
    case Qt::Key_W:
        Pressup();
        break;
     case Qt::Key_A:
        PressLeft();
        break;
    case Qt::Key_S:
        Pressdown();
        break;
    case Qt::Key_D:
        PressRight();
        break;
    default:
        return;
    }
    //myrand();
    update();

}
void MainWindow::slotStart()
{
    //游戏开始或重新的初始化过程
    QMessageBox::about(this,"游戏规则","WASD控制全部方块上下左右移动");
    score=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            s[i][j]=0;

        }

    }
    button->setText("重新游戏");
    int randi=qrand()%4;//
    int randj=qrand()%4;
    s[randi][randj]=2;
    state =true;
    update();

}

void MainWindow::Pressup()
{
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(s[i][j]==0)
            {
                continue;

            }
            for(int p=0;p<j;p++)
            {
                if(s[i][p]==0)
                {
                    s[i][p]=s[i][j];
                    s[i][j]=0;
                    break;

                }

            }

        }

    }
    //相加
    for(int i=0;i<4;i++)
    {
        for(int j =0;j<4;j++)
        {
            if(s[i][j]==s[i][j+1])
            {
                s[i][j]=2*s[i][j];
                s[i][j+1]=0;
                score+=s[i][j];
                for(int p=j+2;p<4;p++)
                {
                    s[i][p-1]=s[i][p];
                    s[i][p]=0;
                }

            }


        }

    }


}
void MainWindow::Pressdown()
{
    //移动
        for (int i=0;i<4;i++) {
            for (int j=2;j>=0;j--) {
                if(s[i][j]==0)continue;
                for (int p=3;p>j;p--) {
                    //查看前面是否有空格子可移动
                    if(s[i][p]==0){
                        s[i][p]=s[i][j];
                        s[i][j]=0;
                        break;
                    }
                }
            }
        }
        //相加
        for (int i=0;i<4;i++) {
            for (int j=3;j>0;j--) {
                if(s[i][j]==s[i][j-1]){
                    s[i][j]=2*s[i][j];
                    s[i][j-1]=0;
                    score+=s[i][j];
                    for (int p=j-2;p>=0;p--)
                    {
                        s[i][p+1]=s[i][p];
                        s[i][p]=0;
                    }
                }
            }
        }



}
void MainWindow::PressLeft()
{
    for (int j=0;j<4;j++) {
            for (int i=1;i<4;i++) {
                if(s[i][j]==0){
                    continue;
                }
                for (int p=0;p<i;p++) {
                    //查看前面是否有空格可移入
                    if(s[p][j] == 0){
                        s[p][j] = s[i][j];
                        s[i][j] = 0;
                        break;
                    }
                }
            }
        }



    //相加
    for(int j=0;j<4;j++)
    {
        for(int i=0;i<3;i++)
        {
            if(s[i][j]==s[i+1][j])
            {
                s[i][j]=s[i][j]*2;
                score+=s[i][j];
                s[i+1][j]=0;
                for(int p=i+2;p<4;p++)
                {
                    s[p-1][j]=s[p][j];
                    //s[p][j]=0;

                }

            }

        }

    }

}
void MainWindow::PressRight()
{
    //移动
        for (int j=0;j<4;j++) {
            for (int i=2;i>=0;i--) {
                if(s[i][j]==0){
                    continue;
                }
                for (int p=3;p>i;p--) {
                    //查看前面是否有空格可移入
                    if(s[p][j] == 0){
                        s[p][j] = s[i][j];
                        s[i][j] = 0;
                        break;
                    }
                }
            }
        }
        //相加
        for (int j=0;j<4;j++)
        {
            for (int i=3;i>=0;i--)
            {
                if(s[i][j]==s[i-1][j])
                {
                    s[i][j]=s[i][j]*2;
                    s[i-1][j]=0;
                    score+=s[i][j];
                    for(int p=i-2;p>=0;p--)
                    {
                        s[p+1][j] = s[p][j];
                        s[p][j]=0;
                    }
                }
            }
        }



}

void MainWindow::myRand()
{
    //找空的格子
    int i=0;
    int j=0;
    //
    struct Ns n[15];
    int ni=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(s[i][j]==0)
            {
                n[ni].i=i;
                n[ni].j=j;
                ni++;
            }

        }

    }
    //判断是否结束
    if(ni==0)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<3;j++)
            {
                if(s[i][j]==s[i][j+1])
                {
                    return;
                }



            }

        }
        for(j=0;j<4;j++)
        {
            for(i=0;i<3;i++)
            {
                if(s[i][j]==s[i+1][j])
                {
                    return;
                }



            }

        }
        QMessageBox::about(this,"游戏结束","分数为："+QString::number(score)+" ");
        return;
    }
    int rand=qrand()%ni;
        s[n[rand].i][n[rand].j]=2;
}
