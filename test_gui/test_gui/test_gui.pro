#-------------------------------------------------
#
# Project created by QtCreator 2019-08-20T10:56:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_gui
TEMPLATE = app


SOURCES += main.cpp\
        testopencv.cpp

HEADERS  += testopencv.h

FORMS    += testopencv.ui


INCLUDEPATH += /lccRoot/programs/opencv-3.4.0/include\
                /lccRoot/programs/opencv-3.4.0/include/opencv\
                /lccRoot/programs/opencv-3.4.0/include/opencv2


LIBS += -L/lccRoot/programs/opencv-3.4.0/lib/ \
-lopencv_calib3d\
-lopencv_core\
-lopencv_features2d\
-lopencv_flann\
-lopencv_highgui\
-lopencv_imgcodecs\
-lopencv_imgproc\
-lopencv_ml\
-lopencv_objdetect\
-lopencv_photo\
-lopencv_shape\
-lopencv_stitching\
-lopencv_superres\
-lopencv_videoio\
-lopencv_video









