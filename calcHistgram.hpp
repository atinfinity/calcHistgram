#pragma once
#include <opencv2/core.hpp>

double launch_calcHistgram(const cv::Mat& src, std::vector<int>& hist, const int loop_num);
