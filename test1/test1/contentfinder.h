#ifndef CONTENTFINDER_H
#define CONTENTFINDER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

class ContentFinder
{
private:
    float hranges[2];
    const float *ranges[3];
    int     channels[3];
    float   threshold;
    cv::MatND histogram;
public:
    ContentFinder();
    void        setThreshold(float t);
    float       getThreshold();
    void        setHistogram(const cv::MatND &h);
    cv::Mat     find(const cv::Mat &image,
                     float minValue, float maxValue,
                     int *chnnls, int dim);
};

#endif // CONTENTFINDER_H
