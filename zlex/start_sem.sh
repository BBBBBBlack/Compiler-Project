#!/bin/bash

# g++ run_zlex.cpp -o run_zlex -std=c++17 -lstdc++fs -I/usr/local/include/nlohmann

config_file=$1
./run_zlex "$config_file"
# 创建一个名为build的目录，如果它不存在的话
# rm -rf build
mkdir -p build

# 进入build目录
cd build

# 运行CMake以配置项目
cmake ..

# 编译项目
make zlex

# 运行项目（假设生成的可执行文件名为my_project）
./zlex
