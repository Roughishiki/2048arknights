#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "LogWidget.h"
#include <QMainWindow>
#include<QPushButton>
#include<QMessageBox>
#include<QTime>
#include<QPainter>
#include<QKeyEvent>
#include<QIcon>
#include<QPen>
#include<QPalette>
#include <QMenuBar>
#include <QMenu>
#include<QToolBar>
#include<QLabel>
#include <QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    QPushButton *button;
    int s[4][4];
    int score=0;
    void Pressup();
    void Pressdown();
    void PressLeft();
    void PressRight();
    void myRand();
    void gameover1();
    void gameover2();
    void gameover3();
    struct Ns
    {
        int i;
        int j;

    };
    bool state;//true false 判断状态
public slots:
    void slotStart();
private:
    Ui::MainWindow *ui;
    LogWidget * m_log;
    QLabel*		 m_gameOver;
    QLabel*		 m_gameOverText;
};
#endif // MAINWINDOW_H
