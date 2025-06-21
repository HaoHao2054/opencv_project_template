//
// Created by 20541 on 25-6-19.
//

#ifndef SHOWIMAGESINGRID_H
#define SHOWIMAGESINGRID_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm> // 用于 std::min
#include <opencv2/opencv.hpp>

/**
 * @brief 在一个网格中显示多张图片，保持每张图片的原始宽高比。
 * * @param images 待显示的图片向量。
 * @param windowName 显示窗口的标题。
 * @param cell_size 网格中每个单元格的尺寸（边界框）。
 */
void showImagesInGrid(const std::vector<cv::Mat> &images,
                      const std::string &windowName = "Image Grid (Aspect Ratio Preserved)",
                      const cv::Size &cell_size = cv::Size(500, 480));

#endif //SHOWIMAGESINGRID_H
