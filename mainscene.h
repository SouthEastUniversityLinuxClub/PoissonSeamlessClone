#ifndef MAINSCENE_H
#define MAINSCENE_H
#include <QGraphicsScene>
#include <QString>
#include <QGraphicsItemGroup>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include "status.h"

using namespace cv;

class MainScene : public QGraphicsScene
{
public:
    MainScene();
    void press(QMouseEvent* event);//鼠标点击处理函数
    void moving(QMouseEvent* event);//鼠标移动处理函数
    void release(QMouseEvent* event);//鼠标释放处理函数

    bool open();
    void setRect(QRect* rect);
    void removeRectItem();

    cv::Mat QImage2cvMat(QImage image);
    QImage cvMat2QImage(const cv::Mat& mat);

    Status status;
//private:
    QGraphicsPixmapItem* pixmapItem;
    QGraphicsRectItem* rectItem;
    QString path;
    QImage image;
    QGraphicsItemGroup* group;
    QPoint start,end;
    QRect* rect;
    Mat rectMat,originalMat;
    Mat result;
    bool hasRectItem;
};

#endif // MAINSCENE_H
