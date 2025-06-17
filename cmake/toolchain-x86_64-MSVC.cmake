# 设置C++标准
# 推荐使用C++11或更高版本
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 修改MSVC字符编码为UTF-8
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

