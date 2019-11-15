
#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <string>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;
using namespace cv;

#include <sys/time.h>
long get_cur_ms()
{
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);

    return long(tv.tv_sec*1000 + tv.tv_usec/1000);
}

int test_matchTemplate()
{
    Mat whole = imread("../src/images/whole.bmp", IMREAD_COLOR);
    Mat tpl = imread("../src/images/template.bmp", IMREAD_COLOR);

    Mat img_display;
    whole.copyTo(img_display);

    Mat result;
    result.create(whole.rows-tpl.rows+1, whole.cols-tpl.cols+1, CV_32FC1);

long cur = get_cur_ms();
    matchTemplate(whole, tpl, result, CV_TM_SQDIFF);
    normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
    double minVal, maxVal;
    Point  minLoc, maxLoc, matchLoc;
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
cout << " spend time: " << get_cur_ms() -cur << " ms" << endl;
//    if( match_method  == TM_SQDIFF || match_method == TM_SQDIFF_NORMED )
//        matchLoc = minLoc;
//    else
//        matchLoc = maxLoc;
    matchLoc = minLoc;

    rectangle(img_display, matchLoc,
              Point( matchLoc.x + tpl.cols , matchLoc.y + tpl.rows ),
              Scalar(255,255,0), 2, 8, 0 );
    rectangle( result, matchLoc,
              Point( matchLoc.x + tpl.cols , matchLoc.y + tpl.rows ),
              Scalar(255,0,255), 2, 8, 0 );
    imshow( "Source Image", img_display );
    imshow( "Result window", result );



    waitKey(0);

    return 0;
}
