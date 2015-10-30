#include "segmentationeventhandler.h"

SegmentationEventHandler::SegmentationEventHandler() {
}

SegmentationEventHandler::~SegmentationEventHandler() {

}

Mat SegmentationEventHandler::QImage2Mat(const QImage& src) {
    unsigned int height = src.height();
    unsigned int width = src.width();
    cv::Mat3f dest(height, width);
    
    for (unsigned int i = 0; i < height; i++) {
        cv::Vec3f* destrow = dest[i];
        for (unsigned int j = 0; j < width; j++) {
            QRgb pxl = src.pixel(j, i);
            destrow[j] = cv::Vec3f(qBlue(pxl), qGreen(pxl), qRed(pxl));
        }
    }

    return dest;
}

QImage SegmentationEventHandler::Mat2QImage(const Mat& src)
{
    QImage dest(src.rows, src.cols, QImage::Format_RGB32);
    
    for (unsigned int i = 0; i < src.rows; i++) {
        for (unsigned int j = 0; j < src.cols; j++) {
            Vec3f data = src.at<Vec3f>(i, j);
            QRgb pixel = qRgb((int)(data[0]), (int)(data[1]), (int)(data[2]));
            dest.setPixel(j, i, pixel);
        }
    }

    return dest;
}

QImage SegmentationEventHandler::loadImage(const string& filePath) {
    QImage image;
    image.load(filePath.c_str());
    return image;
}

QImage SegmentationEventHandler::segment(
    const QImage& img, const Mat& backgroundImage, const Mat& foregroundImage, const double& beta) {
    Mat inputImage = QImage2Mat(img);

    normalize(inputImage, inputImage, 0.0, 1.0, NORM_MINMAX, CV_32FC3);

    return Mat2QImage(
        segmenter.segment(inputImage, backgroundImage, foregroundImage, beta));
}

bool SegmentationEventHandler::saveImage(
    const QImage& img, const string& filePath) {
    QImage image = img;
    image.save(filePath.c_str());

    return true;
}