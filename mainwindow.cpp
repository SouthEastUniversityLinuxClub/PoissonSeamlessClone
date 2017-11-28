#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->subWindows = QVector<QMdiSubWindow*>();
    this->views = QVector<MainView*>();
    this->scenes = QVector<MainScene*>();

    this->showMaximized();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QMdiSubWindow* subWindow = new QMdiSubWindow;
    MainScene* scene = new MainScene;
    MainView* view = new MainView(scene);
    view->setScene(scene);
    subWindow->setWidget(view);
    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    ui->mdiArea->addSubWindow(subWindow);


    if(scene->open())
    {
        scene->update(view->rect());
        view->resize(scene->width(),scene->height());
        view->setAlignment(Qt::AlignLeft|Qt::AlignTop);
        view->setRenderHint(QPainter::Antialiasing);
        subWindow->resize(view->size());
        subWindow->show();

        scenes.push_back(scene);
        views.push_back(view);
        subWindows.push_back(subWindow);
    }
}

void MainWindow::on_actionSelect_triggered()
{
    for(int i=0;i<scenes.size();i++)
    {
        scenes[i]->status.status="select";
    }
}

void MainWindow::on_actionClone_triggered()
{
    for(int i=0;i<scenes.size();i++)
    {
        scenes[i]->status.status="clone";
        if(scenes[i]->hasRectItem)
        {
            qDebug()<<i;
//            src = scenes[i]->rectMat;
        }
//        if(subWindows[i]->isActiveWindow())
//        {
//            scenes[i]->rectMat = src;
//        }
    }
}

void MainWindow::on_actionDelete_triggered()
{
    for(int i=0;i<subWindows.size();i++)
    {
        if(subWindows[i]->isActiveWindow())
        {
            scenes[i]->removeRectItem();
        }
    }
}
