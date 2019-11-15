QT += core
QT -= gui

TARGET = test_matchTemplate
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    matchtemplate.cpp

INCLUDEPATH += /lccRoot/programs/x86_64/opencv-3.4.0/include\
                /lccRoot/programs/x86_64/opencv-3.4.0/include/opencv\
                /lccRoot/programs/x86_64/opencv-3.4.0/include/opencv2


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

HEADERS += \
    contentfinder.h \
    morphofeatures.h \
    watershedsegmenter.h \
    laplacianzc.h

QMAKE_CFLAGS += -g
