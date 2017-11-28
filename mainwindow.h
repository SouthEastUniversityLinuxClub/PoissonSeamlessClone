#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVector>
#include <QMdiArea>
#include <QMdiSubWindow>
#include "mainscene.h"
#include "mainview.h"
#include "status.h"
#include <QDebug>
#include <opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actionOpen_triggered();

    void on_actionSelect_triggered();

    void on_actionClone_triggered();

    void on_actionDelete_triggered();

private:
    Ui::MainWindow *ui;
    QVector<MainView*> views;
    QVector<MainScene*> scenes;
    QVector<QMdiSubWindow*> subWindows;
    Mat src;
};


#endif // MAINWINDOW_H
