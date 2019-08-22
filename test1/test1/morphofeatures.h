#ifndef MORPHOFEATURES_H
#define MORPHOFEATURES_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "contentfinder.h"

class MorphoFeatures
{
private:
    int         threshold;
    cv::Mat     cross;
    cv::Mat     diamond;
    cv::Mat     square;
    cv::Mat     x;
public:
    MorphoFeatures();
    cv::Mat     getEdges(const cv::Mat &image);
    void        applyThreshold(cv::Mat &result);
    void        setThreshold(int threshold);
    cv::Mat     getCorners(const cv::Mat &image);

    void        drawOnImage(const cv::Mat &binary, cv::Mat &image);
};

#endif // MORPHOFEATURES_H
