#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QObject>
#include <QSplashScreen>
#include <QPixmap>
#include <QWidget>
#include <QProgressBar>
#include <QTime>
#include <QCoreApplication>

class Dialog : public QDialog
{ Q_OBJECT
   public:
    Dialog(QWidget *parent = nullptr);
     ~Dialog();
     //头文件中进行声明
     void paintEvent(QPaintEvent* event);
     void timerEvent(QTimerEvent* event);
     int curIndex;
     void InitPixmap();
 private:
     QPixmap pixmap[12];


};


#endif // DIALOG_H
