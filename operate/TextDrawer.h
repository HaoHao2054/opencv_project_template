//
// Created by 20541 on 25-6-21.
//

#ifndef TEXTDRAWER_H
#define TEXTDRAWER_H

#include <opencv2/opencv.hpp>
#include <string>

// --- 进阶的 TextDrawer 类 ---
class TextDrawer {
public:
    // 构造函数，用于设置默认文本样式
    TextDrawer(int fontFace = cv::FONT_HERSHEY_SIMPLEX, double fontScale = 1.0,
               const cv::Scalar &color = cv::Scalar(255, 255, 255), int thickness = 1)
        : m_fontFace(fontFace), m_fontScale(fontScale), m_color(color), m_thickness(thickness) {
    }

    // 核心方法：在指定中心点绘制居中文字
    void drawCentered(cv::Mat &img, const std::string &text, const cv::Point &centerPoint) const {
        int baseline = 0;
        cv::Size textSize = cv::getTextSize(text, m_fontFace, m_fontScale, m_thickness, &baseline);
        cv::Point textOrigin(centerPoint.x - textSize.width / 2,
                             centerPoint.y + textSize.height / 2);

        cv::putText(img, text, textOrigin, m_fontFace, m_fontScale, m_color, m_thickness);
    }

    // 也可提供一个绘制非居中文字的方法
    void draw(cv::Mat &img, const std::string &text, const cv::Point &origin) const {
        cv::putText(img, text, origin, m_fontFace, m_fontScale, m_color, m_thickness);
    }

    // 可以提供修改样式的接口
    void setStyle(double newScale, const cv::Scalar &newColor) {
        m_fontScale = newScale;
        m_color = newColor;
    }

private:
    // 成员变量，保存文本样式
    int m_fontFace;
    double m_fontScale;
    cv::Scalar m_color;
    int m_thickness;
};

#endif //TEXTDRAWER_H
