#include "calcHistgram.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#define VIEW_HISTGRAM

void viewHistgram(std::vector<int>& hist, const int bin_size)
{
    const int max = *std::max_element(hist.begin(), hist.end());
    cv::Mat hist_img(cv::Size(bin_size, bin_size), CV_8UC1, cv::Scalar(0));

    int i = 0;
    for (auto x : hist)
    {
        cv::line(hist_img, cv::Point(i, (bin_size - 1)), cv::Point(i, (int)((bin_size - 1) - ((bin_size - 1) * ((float)x / max)))), cv::Scalar(255));
        i++;
    }

    cv::imshow("hist_img", hist_img);
    cv::waitKey(0);
}

int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: ./calcHistgram <image_file>" << std::endl;
        return -1;
    }

    cv::Mat src = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (src.empty())
    {
        std::cout << "could not load image." << std::endl;
        return -1;
    }

    double scale = 8.0;
    cv::Mat img;
    cv::resize(src, img, cv::Size(), scale, scale, cv::INTER_LINEAR);
    std::cout << "image size = " << img.size() << std::endl;

    // calc histgram
    const int loop_num = 10;
    const size_t bin_size = 256;
    std::vector<int> hist(bin_size, 0);
    double time = launch_calcHistgram(img, hist, loop_num);
    std::cout << "time = " << time << " ms." << std::endl;

#ifdef VIEW_HISTGRAM
    viewHistgram(hist, bin_size);
#endif

    return 0;
}
