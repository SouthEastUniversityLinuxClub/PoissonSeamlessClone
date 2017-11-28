#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
//LIBS += /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so \
///usr/lib/x86_64-linux-gnu/libopencv_contrib.so \
///usr/lib/x86_64-linux-gnu/libopencv_core.so \
///usr/lib/x86_64-linux-gnu/libopencv_features2d.so \
///usr/lib/x86_64-linux-gnu/libopencv_flann.so \
///usr/lib/x86_64-linux-gnu/libopencv_gpu.so \
///usr/lib/x86_64-linux-gnu/libopencv_highgui.so \
///usr/lib/x86_64-linux-gnu/libopencv_imgproc.so \
///usr/lib/x86_64-linux-gnu/libopencv_legacy.so \
///usr/lib/x86_64-linux-gnu/libopencv_ml.so \
///usr/lib/x86_64-linux-gnu/libopencv_objdetect.so \
///usr/lib/x86_64-linux-gnu/libopencv_ocl.so \
///usr/lib/x86_64-linux-gnu/libopencv_photo.so \
///usr/lib/x86_64-linux-gnu/libopencv_stitching.so \
///usr/lib/x86_64-linux-gnu/libopencv_superres.so \
///usr/lib/x86_64-linux-gnu/libopencv_ts.so \
///usr/lib/x86_64-linux-gnu/libopencv_video.so \
///usr/lib/x86_64-linux-gnu/libopencv_videostab.so
