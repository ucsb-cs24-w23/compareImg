#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
using namespace cv;
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << -1 << std::flush;
        return 1;
    }

    std::string image_path1;
    std::string image_path2;

    Mat img1;
    Mat img2;

    try
    {
        image_path1 = samples::findFile(argv[1]);
        image_path2 = samples::findFile(argv[2]);
        img1 = imread(image_path1, IMREAD_COLOR);
        img2 = imread(image_path2, IMREAD_COLOR);
    }
    catch (Exception &e)
    {
        std::cerr << -2 << std::flush;
        return 2;
    }

    if (img1.empty() || img2.empty())
    {
        std::cerr << -3 << std::flush;
        return 2;
    }
    Mat out;
    absdiff(img1, img2, out);
    double diff = 0;
    diff += sum(out)[0];
    diff += sum(out)[1];
    diff += sum(out)[2];
    diff += sum(out)[3];
    std::cout << diff << std::flush;
    return 0;
}