//
// Created by 20541 on 25-6-19.
//
#include "showImagesInGrid.h"

void showImagesInGrid(const std::vector<cv::Mat> &images,
                      const std::string &windowName,
                      const cv::Size &cell_size) {
    if (images.empty()) {
        std::cout << "Warning: No images to display." << std::endl;
        return;
    }

    const int imageCount = images.size();
    int cols = static_cast<int>(std::ceil(std::sqrt(imageCount)));
    int rows = static_cast<int>(std::ceil(static_cast<double>(imageCount) / cols));

    const int canvasWidth = cols * cell_size.width;
    const int canvasHeight = rows * cell_size.height;
    cv::Mat canvas(canvasHeight, canvasWidth, CV_8UC3, cv::Scalar(20, 20, 20));

    for (size_t i = 0; i < imageCount; ++i) {
        const cv::Mat &originalImage = images[i];
        if (originalImage.empty()) continue;

        // ... (缩放逻辑保持不变) ...
        double originalWidth = originalImage.cols;
        double originalHeight = originalImage.rows;

        double scaleX = static_cast<double>(cell_size.width) / originalWidth;
        double scaleY = static_cast<double>(cell_size.height) / originalHeight;
        double scale = std::min(scaleX, scaleY);
        cv::Size newSize(static_cast<int>(originalWidth * scale), static_cast<int>(originalHeight * scale));
        cv::Mat resizedImage;
        cv::resize(originalImage, resizedImage, newSize, 0, 0, cv::INTER_AREA);

        // --- 新增的核心逻辑：确保通道数匹配 ---
        cv::Mat imageToCopy = resizedImage; // 默认直接使用缩放后的图
        if (resizedImage.channels() == 1 && canvas.channels() == 3) {
            // 如果缩放后的图是1通道，而画布是3通道
            // 则将灰度图转换为BGR图再进行复制
            cv::cvtColor(resizedImage, imageToCopy, cv::COLOR_GRAY2BGR);
        }
        // 后续所有操作都使用 imageToCopy
        // -----------------------------------------

        // ... (计算ROI的逻辑保持不变) ...
        const int cell_col = i % cols;
        const int cell_row = i / cols;
        const int cell_X = cell_col * cell_size.width;
        const int cell_Y = cell_row * cell_size.height;

        // 注意这里 newSize 的宽度和高度需要从 imageToCopy 获取，因为转换后的图尺寸可能不变，但最好保持一致性
        const int offsetX = (cell_size.width - imageToCopy.cols) / 2;
        const int offsetY = (cell_size.height - imageToCopy.rows) / 2;

        cv::Rect finalRoi(cell_X + offsetX, cell_Y + offsetY, imageToCopy.cols, imageToCopy.rows);

        // 7. 将处理后的图片复制到画布的指定位置
        imageToCopy.copyTo(canvas(finalRoi));
    }

    cv::imshow(windowName, canvas);
}
