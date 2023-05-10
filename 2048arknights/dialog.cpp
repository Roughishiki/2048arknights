#include "dialog.h"

void Dialog::InitPixmap()
{//将资源文件加载进pixmap数组中
    for(int i=0;i<12;i++)
    {
        QString fileName=QString(":/new/prefix1/sn/IMG000%0.bmp").arg(i+1,2,10,QLatin1Char('0'));//构造资源文件名
        QPixmap map(fileName);//将资源文件名传给map
        pixmap[i]=map;//map传入pixmap数组
    }
}
void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect q1(0,0,500,281);//构造图片大小的矩形
    QRect q2(0,0,width(),height());//构造窗口大小的矩形
    painter.drawPixmap(q2,pixmap[curIndex],q1);//实现将q1画入q2，画的内容为pixmap中对应的图片
}
