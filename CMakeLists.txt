# 1. 设置CMake最低版本要求和项目信息
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和版本
project(MyOpenCVProject)

# 编译工具链设置
include(cmake/toolchain-x86_64-MSVC.cmake)
# 包管理
include(cmake/packages.cmake)


add_executable(${PROJECT_NAME}
        main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${OpenCV_INCLUDE_DIRS}

)

target_link_libraries(${PROJECT_NAME}
        ${OpenCV_LIBS}
)

# 7. (可选) 为Windows平台设置输出目录
# 这段代码可以让你生成的.exe文件和.dll文件都在同一个目录下，方便运行
if (WIN32)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

    # 在Debug模式下，输出调试信息
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Build type: Debug")
    endif ()
endif ()

