#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "contentfinder.h"
//using namespace cv;

void salt(cv::Mat &image, int n)
{
    for(int k=0; k<n; k++){
        int i = rand()%image.cols;
        int j = rand()%image.rows;

        if(image.channels() == 1)
            image.at<uchar>(j, i) = 255;
        else if(image.channels()==3){
            image.at<cv::Vec3b>(j,i)[0] = 255;
            image.at<cv::Vec3b>(j,i)[1] = 255;
            image.at<cv::Vec3b>(j,i)[2] = 255;
        }
    }
}

class Histogram1D{
public:
    int     histSize[1];
    float   hranges[2];
    const float *ranges[1];
    int     channels[1];

public:
    Histogram1D(){
        histSize[0] = 256;
        hranges[0]  = 0.0;
        hranges[1]  = 255.0;
        ranges[0]   = hranges;
        channels[0] = 0;
    }
    cv::MatND getHistogram(const cv::Mat &image);
    cv::Mat getHistogramImage(const cv::Mat &image);
    cv::Mat applyLookup(const cv::Mat &image, const cv::Mat &lookup);
    cv::Mat stretch(const cv::Mat &image, int minValue=0);
};

cv::MatND Histogram1D::getHistogram(const cv::Mat &image)
{
    cv::MatND hist;
    cv::calcHist(&image,
                 1,
                 channels,
                 cv::Mat(),
                 hist,
                 1,
                 histSize,
                 ranges);
    return hist;
}

cv::Mat Histogram1D::getHistogramImage(const cv::Mat &image)
{
    cv::MatND hist = getHistogram(image);
    double maxVal = 0, minVal = 0;
    cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);
    cv::Mat histImg(histSize[0], histSize[0], CV_8U, cv::Scalar(255));
    int hpt = static_cast<int>(0.9*histSize[0]);
    for(int h=0; h<histSize[0]; h++){
        float binVal = hist.at<float>(h);
        int intensity = static_cast<int>(binVal*hpt/maxVal);
        cv::line(histImg, cv::Point(h, histSize[0]),
                cv::Point(h, histSize[0]-intensity),
                cv::Scalar::all(0));
    }
    return histImg;
}

cv::Mat Histogram1D::applyLookup(const cv::Mat &image, const cv::Mat &lookup)
{
    cv::Mat res;
    cv::LUT(image, lookup, res);

    return res;
}

cv::Mat Histogram1D::stretch(const cv::Mat &image, int minValue)
{
    cv::MatND hist = getHistogram(image);

    int imin = 0;
    for(; imin<histSize[0]; imin++){
        if(hist.at<float>(imin) > minValue)
            break;
    }

    int imax = histSize[0] -1 ;
    for(; imax>=0; imax--){
        if(hist.at<float>(imax) > minValue)
            break;
    }

    std::cout<<"min:"<<imin<<" imax:"<<imax<<std::endl;

    int dim(256);
    cv::Mat lookup(1, &dim, CV_8U);
    for(int i=0; i<256; i++){
        if(i<imin)
            lookup.at<uchar>(i) = 0;
        else if(i<imax)
            lookup.at<uchar>(i) = 255;
        else
            lookup.at<uchar>(i) = static_cast<uchar>(
                   255.0*(i-imin)/(imax-imin) +0.5);
    }
    cv::Mat result;
    result = applyLookup(image, lookup);

    return result;
}

/*

int main()
{
    cv::Mat image = cv::imread("3.jpg");
    //cv::namedWindow("My Image");
    //cv::imshow("My Image", image);

    //cv::cvtColor(image, image, CV_BGR2GRAY);
    cv::imshow("My Image", image);

    std::cout<<"size,"<<image.size().height<<","
        <<image.size().width<<" depth:"<<image.depth()<<std::endl;

    Histogram1D h;
//    cv::imshow("Histogram", h.getHistogramImage(image));

//    cv::Mat thded;
//    cv::threshold(image, thded, 150, 255, cv::THRESH_BINARY);

//    cv::Mat stretched;
//    stretched = h.stretch(image, 3000);

//    cv::imshow("thded", thded);
//
//    cv::imshow("stretched", stretched);
//    cv::imshow("stretched hist", h.getHistogramImage(stretched));

    cv::Mat roi;
    roi = image(cv::Rect(320, 180, 100, 90));
    cv::imshow("roi", roi);

    cv::MatND hist = h.getHistogram(roi);

    ContentFinder finder;
    finder.setHistogram(hist);
    finder.setThreshold(0.1f);

    int chnnls[3] = {0, 1, 2};
    cv::Mat result = finder.find(image, 60.0, 255.0, chnnls, 3);
    imshow("finder", result);

    cv::waitKey(0);
    return 0;
}
*/


/*
// get binary image
int main()
{
    cv::Mat image = cv::imread("4.jpg", cv::IMREAD_GRAYSCALE);
    std::cout<<image.channels()<<std::endl;

    cv::imshow("image", image);

    cv::Mat thded;
    cv::threshold(image, thded, 60, 255, cv::THRESH_BINARY);
    cv::imshow("thded", thded);


    cv::waitKey(0);
    return 0;
}
*/
/*
 // erode and dilate
int main()
{
    cv::Mat image = cv::imread("binary.bmp");
    std::cout<<image.channels()<<std::endl;
    cv::imshow("image", image);

    cv::Mat eroded;
    cv::erode(image, eroded, cv::Mat());
    cv::imshow("eroded", eroded);

    cv::Mat dilated;
    cv::dilate(image, dilated, cv::Mat());
    cv::imshow("dilated", dilated);

    cv::waitKey(0);
    return 0;
}
*/

#include "morphofeatures.h"
int main()
{
    cv::Mat image = cv::imread("4.jpg");
    cv::cvtColor(image, image, CV_BGR2GRAY);

    std::cout<<image.channels()<<std::endl;
    cv::imshow("image", image);

    MorphoFeatures morpho;
    morpho.setThreshold(50);

//    cv::Mat edges = morpho.getEdges(image);
//    cv::imshow("edge", edges);
    cv::Mat corners = morpho.getCorners(image);
    //cv::imshow("corners", corners);

    morpho.drawOnImage(corners, image);
    cv::imshow("cornered image", image);

    cv::waitKey(0);
    return 0;
}
