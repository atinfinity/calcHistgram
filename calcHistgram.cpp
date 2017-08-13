#include "calcHistgram.hpp"

void calcHistgram(const cv::Mat& src, int* hist)
{
    for (int y = 0; y < src.rows; y++)
    {
        for (int x = 0; x < src.cols; x++)
        {
            hist[src.ptr<uchar>(y)[x]]++;
        }
    }
}

double launch_calcHistgram(const cv::Mat& src, std::vector<int>& hist, const int loop_num)
{
    CV_Assert(!src.empty());
    CV_Assert(hist.size() > 0);

    cv::TickMeter tm;
    double time = 0.0;

    for (int i = 0; i <= loop_num; i++)
    {
        // zero clear
        std::fill(hist.begin(), hist.end(), 0);

        tm.reset();
        tm.start();

        calcHistgram(src, &hist[0]);

        tm.stop();
        time += (i > 0) ? (tm.getTimeMilli()) : 0.0;
    }
    time /= loop_num;

    return time;
}
