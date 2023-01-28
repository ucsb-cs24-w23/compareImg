#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
extern double compareImg(std::string answer, std::string key)
{
    std::string image_path1;
    std::string image_path2;

    Mat img1;
    Mat img2;

    try
    {
        image_path1 = samples::findFile(answer);
        image_path2 = samples::findFile(key);
        img1 = imread(image_path1, IMREAD_COLOR);
        img2 = imread(image_path2, IMREAD_COLOR);
    }
    catch (Exception &e)
    {
        return -3;
    }

    if (img1.empty() || img2.empty())
    {
        return -2;
    }
    Mat out;
    absdiff(img1, img2, out);
    double diff = 0;
    diff += sum(out)[0];
    diff += sum(out)[1];
    diff += sum(out)[2];
    diff += sum(out)[3];
    return diff;
}