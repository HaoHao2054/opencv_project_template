# 查找OpenCV库
# REQUIRED 参数表示如果找不到OpenCV，CMake会报错并停止构建
# COMPONENTS 参数指定你需要使用的OpenCV模块，可以减少最终程序的体积
# 常见的模块有：core, highgui, imgcodecs, imgproc, videoio, objdetect等
find_package(OpenCV REQUIRED COMPONENTS core highgui imgproc)

# 检查是否成功找到OpenCV
if(OpenCV_FOUND)
    message(STATUS "OpenCV found: ${OpenCV_LIBS}")
else()
    message(FATAL_ERROR "OpenCV not found")
endif()