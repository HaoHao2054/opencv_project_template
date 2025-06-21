#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include "showImagesInGrid.h"
#include "TextDrawer.h"

const std::string image_path = "D:\\桌面文件夹\\图片\\真寻\\真寻2.png";
const std::string windows_name = "image";
const std::string video_bad_apple = "C:\\Users\\20541\\Desktop\\【4K 60FPS】(全站最清晰画质_音频修复)Bad apple！！！坏苹果！！！.mp4";

int main() {
    cv::Mat srcImg = cv::imread(image_path);


    TextDrawer textDrawer(cv::FONT_HERSHEY_SIMPLEX, 2.5, cv::Scalar(255, 255, 255), 3);

    textDrawer.drawCentered(srcImg, "Hello World!", cv::Point(srcImg.cols / 2, srcImg.rows / 2));


    cv::namedWindow(windows_name, cv::WINDOW_NORMAL);
    cv::imshow(windows_name, srcImg);
    cv::resizeWindow(windows_name, 800, 480);

    cv::waitKey(0);
    return 0;
}

