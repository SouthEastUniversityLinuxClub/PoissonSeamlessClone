#include "mainview.h"

MainView::MainView(MainScene *scene)
{
    this->scene = scene;
    setScene(scene);
    r = this->rect();
    scene->setRect(&r);
}
void MainView::mousePressEvent(QMouseEvent *event)
{
    scene->press(event);
}

void MainView::mouseMoveEvent(QMouseEvent *event)
{
    scene->moving(event);
}

void MainView::mouseReleaseEvent(QMouseEvent *event)
{
    scene->release(event);
}
