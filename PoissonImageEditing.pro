#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T23:12:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PoissonImageEditing
TEMPLATE = app

#INCLUDEPATH += /usr/include/opencv2
INCLUDEPATH += /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_calib3d.so \
#/usr/local/lib/libopencv_calib3d.so.3.3 \
/usr/local/lib/libopencv_calib3d.so.3.3.1 \
/usr/local/lib/libopencv_core.so \
/usr/local/lib/libopencv_core.so.3.3 \
/usr/local/lib/libopencv_core.so.3.3.1 \
/usr/local/lib/libopencv_dnn.so \
/usr/local/lib/libopencv_dnn.so.3.3 \
/usr/local/lib/libopencv_dnn.so.3.3.1 \
/usr/local/lib/libopencv_features2d.so \
/usr/local/lib/libopencv_features2d.so.3.3 \
/usr/local/lib/libopencv_features2d.so.3.3.1 \
/usr/local/lib/libopencv_flann.so \
/usr/local/lib/libopencv_flann.so.3.3 \
/usr/local/lib/libopencv_flann.so.3.3.1 \
/usr/local/lib/libopencv_highgui.so \
/usr/local/lib/libopencv_highgui.so.3.3 \
/usr/local/lib/libopencv_highgui.so.3.3.1 \
/usr/local/lib/libopencv_imgcodecs.so \
/usr/local/lib/libopencv_imgcodecs.so.3.3 \
/usr/local/lib/libopencv_imgcodecs.so.3.3.1 \
/usr/local/lib/libopencv_imgproc.so \
/usr/local/lib/libopencv_imgproc.so.3.3 \
/usr/local/lib/libopencv_imgproc.so.3.3.1 \
/usr/local/lib/libopencv_ml.so \
/usr/local/lib/libopencv_ml.so.3.3 \
/usr/local/lib/libopencv_ml.so.3.3.1 \
/usr/local/lib/libopencv_objdetect.so \
/usr/local/lib/libopencv_objdetect.so.3.3 \
/usr/local/lib/libopencv_objdetect.so.3.3.1 \
/usr/local/lib/libopencv_photo.so \
/usr/local/lib/libopencv_photo.so.3.3 \
/usr/local/lib/libopencv_photo.so.3.3.1 \
/usr/local/lib/libopencv_shape.so \
/usr/local/lib/libopencv_shape.so.3.3 \
/usr/local/lib/libopencv_shape.so.3.3.1 \
/usr/local/lib/libopencv_stitching.so \
/usr/local/lib/libopencv_stitching.so.3.3 \
/usr/local/lib/libopencv_stitching.so.3.3.1 \
/usr/local/lib/libopencv_superres.so \
/usr/local/lib/libopencv_superres.so.3.3 \
/usr/local/lib/libopencv_superres.so.3.3.1 \
/usr/local/lib/libopencv_video.so \
/usr/local/lib/libopencv_video.so.3.3 \
/usr/local/lib/libopencv_video.so.3.3.1 \
/usr/local/lib/libopencv_videoio.so \
/usr/local/lib/libopencv_videoio.so.3.3 \
/usr/local/lib/libopencv_videoio.so.3.3.1 \
/usr/local/lib/libopencv_videostab.so \
/usr/local/lib/libopencv_videostab.so.3.3 \
/usr/local/lib/libopencv_videostab.so.3.3.1


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mainview.cpp \
    mainscene.cpp \
    status.cpp

HEADERS += \
        mainwindow.h \
    mainview.h \
    mainscene.h \
    status.h

FORMS += \
        mainwindow.ui
