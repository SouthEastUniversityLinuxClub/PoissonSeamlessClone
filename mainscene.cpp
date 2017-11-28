#include "mainscene.h"

MainScene::MainScene()
{
    group = createItemGroup(*(new QList<QGraphicsItem*>));
    pixmapItem = new QGraphicsPixmapItem();
    rectItem = new QGraphicsRectItem();
    status = Status();
    hasRectItem = false;
}

void MainScene::press(QMouseEvent *event)
{
    if(status.status=="select")
    {
        if(rectItem!=NULL)
            removeItem(rectItem);
        start = end = event->pos();
        rectItem->setRect(*(new QRect(start,end)));
        QPen pen = QPen(QColor("red"));
        pen.setWidth(4);
        rectItem->setPen(pen);
        group->addToGroup(rectItem);
    }
    if(status.status=="clone")
    {
        //        if((rectMat.empty()==false)&&(originalMat.empty()==false))
        if(originalMat.empty()==false)
        {
            if(rectMat.empty())// There's no rectangle on the image and no previous clone
            {
                rectMat = imread("temp1.png");
            }
            else // There exists a rectangle on the image
            {
                if(originalMat.empty()==false)
                    result = originalMat;
                cv::Mat tempMat = imread("temp1.png");
                //                if(tempMat.size!=rectMat.size)
                //                {
                cv::imwrite("temp2.png",result);
                originalMat = imread("temp2.png");
                rectMat = tempMat;
                //                }
            }
            Mat src_mask = 255 * Mat::ones(rectMat.rows,rectMat.cols,rectMat.depth());
            //            Mat src_mask =Mat::zeros(rectMat.rows,rectMat.cols,rectMat.depth());
            cv::Point center = cv::Point(event->pos().x(),event->pos().y());
            //            cv::Point center(originalMat.cols/2,originalMat.rows/2);
            cv::imwrite("temp2.png",originalMat);
            //            originalMat = imread("temp2.png");
            if((event->pos().x()-rectMat.cols/2>0)&&(event->pos().x()+rectMat.cols/2<originalMat.cols)
                    &&(event->pos().y()-rectMat.rows/2>0)&&(event->pos().y()+rectMat.rows/2<originalMat.rows))
            {
                seamlessClone(rectMat,originalMat,src_mask,center,result,cv::NORMAL_CLONE);
            }
            removeItem(pixmapItem);
            cv::imwrite("a.jpg",result);
            image = cvMat2QImage(result);
            QPixmap p = QPixmap::fromImage(image);
            pixmapItem = new QGraphicsPixmapItem();
            pixmapItem->setPixmap(p);
            group->addToGroup(pixmapItem);
        }
        //        Mat src = imread("BearInWater.bmp");
        //        Mat dst = imread("NewBackGround.bmp");
        //        Mat src_mask = 255 * Mat::ones(src.rows, src.cols, src.depth());
        //        // The location of the center of the src in the dst
        //        Point center(dst.cols/2,dst.rows/2);
        //        // Seamlessly clone src into dst and put the results in output
        //        Mat normal_clone;
        //        Mat mixed_clone;
        //        Mat monochrome_clone;
        //        seamlessClone(src, dst, src_mask, center, normal_clone, NORMAL_CLONE);
        //        seamlessClone(src, dst, src_mask, center, mixed_clone, MIXED_CLONE);
        //        seamlessClone(src, dst, src_mask, center, monochrome_clone, MONOCHROME_TRANSFER);
        //        imshow("normal_clone",normal_clone);
        //        imshow("minxed_clone",mixed_clone);
        //        imshow("monochrome_clone",monochrome_clone);
        //        imshow("wood",dst);
        //        imshow("lovepapa",src);
    }
}

void MainScene::moving(QMouseEvent *event)
{
    if(status.status=="select")
    {
        end = event->pos();
        rectItem->setRect(*(new QRect(start,end)));
    }
    if(status.status=="clone")
    {
        //        if((rectMat.empty()==false)&&(originalMat.empty()==false))
        if(originalMat.empty()==false)
        {
            if(rectMat.empty())
            {
                rectMat = imread("temp1.png");
            }
            else
            {
                if(originalMat.empty()==false)
                    result = originalMat;
                cv::Mat tempMat = imread("temp1.png");
                //                if(tempMat.size!=rectMat.size)
                //                {
                cv::imwrite("temp2.png",result);
                originalMat = imread("temp2.png");
                rectMat = tempMat;
                //                }
            }
            Mat src_mask = 255 * Mat::ones(rectMat.rows,rectMat.cols,rectMat.depth());
            cv::Point center = cv::Point(event->pos().x(),event->pos().y());
            cv::imwrite("temp2.png",originalMat);
            originalMat = imread("temp2.png");
            if((event->pos().x()-rectMat.cols/2>0)&&(event->pos().x()+rectMat.cols/2<originalMat.cols)
                    &&(event->pos().y()-rectMat.rows/2>0)&&(event->pos().y()+rectMat.rows/2<originalMat.rows))
            {
                seamlessClone(rectMat,originalMat,src_mask,center,result,cv::NORMAL_CLONE);
            }
            removeItem(pixmapItem);
            cv::imwrite("a.jpg",result);
            image = cvMat2QImage(result);
            QPixmap p = QPixmap::fromImage(image);
            pixmapItem = new QGraphicsPixmapItem();
            pixmapItem->setPixmap(p);
            group->addToGroup(pixmapItem);
        }
    }
}

void MainScene::release(QMouseEvent *event)
{
    if(status.status=="select")
    {
        end = event->pos();
        rectItem->setRect(*(new QRect(start,end)));
        QImage temp = pixmapItem->pixmap().toImage().copy(rectItem->rect().toRect());
        rectMat = QImage2cvMat(temp);

        //for testing
        //        removeItem(pixmapItem);
        //        image = cvMat2QImage(rectMat);
        //        QPixmap p = QPixmap::fromImage(image);
        //        pixmapItem = new QGraphicsPixmapItem();
        //        pixmapItem->setPixmap(p);
        //        group->addToGroup(pixmapItem);

        hasRectItem = true;
    }
    if(status.status=="clone")
    {
        //        if((rectMat.empty()==false)&&(originalMat.empty()==false))
        if(originalMat.empty()==false)
        {
            if(rectMat.empty())
            {
                rectMat = imread("temp1.png");
            }
            else
            {
                if(originalMat.empty()==false)
                    result = originalMat;
                cv::Mat tempMat = imread("temp1.png");
                //                if(tempMat.size!=rectMat.size)
                //                {
                cv::imwrite("temp2.png",result);
                originalMat = imread("temp2.png");
                rectMat = tempMat;
                //                }
            }
            Mat src_mask = 255 * Mat::ones(rectMat.rows,rectMat.cols,rectMat.depth());
            cv::Point center = cv::Point(event->pos().x(),event->pos().y());
            cv::imwrite("temp2.png",originalMat);
            originalMat = imread("temp2.png");
            if((event->pos().x()-rectMat.cols/2>0)&&(event->pos().x()+rectMat.cols/2<originalMat.cols)
                    &&(event->pos().y()-rectMat.rows/2>0)&&(event->pos().y()+rectMat.rows/2<originalMat.rows))
            {
                seamlessClone(rectMat,originalMat,src_mask,center,result,cv::NORMAL_CLONE);
            }
            removeItem(pixmapItem);
            cv::imwrite("a.jpg",result);
            originalMat = result;
            image = cvMat2QImage(result);
            QPixmap p = QPixmap::fromImage(image);
            pixmapItem = new QGraphicsPixmapItem();
            pixmapItem->setPixmap(p);
            group->addToGroup(pixmapItem);
        }
    }
}

bool MainScene::open()
{
    removeItem(pixmapItem);
    path = QFileDialog::getOpenFileName(NULL,tr("Open"),".",tr("Images(*.bmp *.png *.jpg)"));
    if(!path.isEmpty())
    {
        image = QImage(path);
        originalMat = QImage2cvMat(image);
        QPixmap p = QPixmap::fromImage(image);
        pixmapItem = new QGraphicsPixmapItem();
        pixmapItem->setPixmap(p);
        group->addToGroup(pixmapItem);
        return true;
    }
    return false;
}

void MainScene::setRect(QRect *rect)
{
    this->rect = rect;
}

void MainScene::removeRectItem()
{
    if(rectItem!=NULL)
        removeItem(rectItem);
    hasRectItem = false;
}


Mat MainScene::QImage2cvMat(QImage image)
{
    cv::Mat mat;
    switch(image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    imwrite("temp1.png",mat);
    return mat;
}

QImage MainScene::cvMat2QImage(const Mat &mat)
{
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
