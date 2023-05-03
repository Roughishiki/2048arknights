#include "mainwindow.h"
#include "LogWidget.h"
#include <QApplication>
#include <QObject>
#include <QSplashScreen>
#include <QPixmap>
#include <QWidget>
#include <QProgressBar>
#include <QTime>
#include<QDebug>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.setWindowTitle("登录");
        QPixmap pixmap(":/resources/loading.png");
        QSplashScreen *sp = new QSplashScreen(pixmap);

        sp->show();

        QDateTime time=QDateTime::currentDateTime();
        QDateTime curTime = QDateTime::currentDateTime();
        qDebug()<<time.secsTo(curTime);
        while (time.secsTo(curTime)<=5)
        {
            QString str = QString("%1:%2").arg("正在建立精神链接").arg(QString::number(time.secsTo(curTime)));
            sp->showMessage(str,Qt::AlignBottom,QColor(255,255,255,100));
            curTime=QDateTime::currentDateTime();
            a.processEvents();
        }

        sp->finish(&w);
        delete sp;
        sp = nullptr;

    MainWindow x;
  // x.show();
    x.setFixedSize(320,480);
    x.setWindowTitle("2048arknights");


return a.exec();
}
