#include "contentfinder.h"

ContentFinder::ContentFinder()
{
    ranges[0] = hranges;
    ranges[1] = hranges;
    ranges[2] = hranges;
}

void ContentFinder::setThreshold(float t)
{
    threshold = t;
}

float ContentFinder::getThreshold()
{
    return threshold;
}

void ContentFinder::setHistogram(const cv::MatND &h)
{
    histogram = h;
    cv::normalize(histogram, histogram, 1.0);
}

cv::Mat ContentFinder::find(const cv::Mat &image,
                            float minValue, float maxValue,
                            int *chnnls, int dim)
{
    cv::Mat result;
    hranges[0] = minValue;
    hranges[1] = maxValue;

    for(int i=0; i<dim; i++){
        this->channels[i] = chnnls[i];
    }
    cv::calcBackProject(&image, 1,
                        chnnls,
                        histogram,
                        result,
                        ranges,
                        255.0);
    if(threshold > 0.0){
        cv::threshold(result, result, 255*threshold, 255, cv::THRESH_BINARY);
    }
    return result;
}




