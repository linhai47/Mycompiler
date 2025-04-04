# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Mycompiler)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)



# 获取所有源文件
file(GLOB_RECURSE SOURCES "*.cpp")
# 获取所有头文件
file(GLOB_RECURSE HEADERS "*.h")

# 自动处理moc文件
set(CMAKE_AUTOMOC ON)
# 自动处理ui文件
set(CMAKE_AUTOUIC ON)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})


