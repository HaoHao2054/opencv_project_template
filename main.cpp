#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

int main() {
    // 1. 指定你要读取的图片路径
    // **重要提示**: 请将 "D:/path/to/your/image.jpg" 替换为你自己电脑上的一张图片路径。
    // 在Windows上，请使用正斜杠 "/" 或者双反斜杠 "\\" 作为路径分隔符。
    const std::string image_path = "D:\\桌面文件夹\\图片\\真寻\\真寻2.png";

    /* 图像矩阵 */
    cv::Mat image;
    /* 图片文件名 */
    image = cv::imread(image_path, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
    }
    else {
        /* 窗口的名字 和 要显示的图像矩阵 */
        cv::imshow("image", image);
    }

    /* 等待任意按键后退出 */
    // cv::waitKey(); // 不按就不退出
    cv::waitKey(3000); // 等待3000毫秒（3秒）后退出

    return 0;
}