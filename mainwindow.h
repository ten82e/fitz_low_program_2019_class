#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QString>
#include <QMouseEvent>
#include <QWheelEvent>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <unistd.h>
#include <iostream>
#include <string>
#include <QtGui>
#include <QWidget>
#include <QHoverEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *object, QEvent *event);
    //bool underMouse();
    //void leaveEvent(QEvent *event);


private slots:
    void on_posis_clicked();

    void on_RB_clicked();

    void on_LB_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
