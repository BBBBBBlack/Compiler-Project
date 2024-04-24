#!/bin/bash

./run_zlex config.json
# 创建一个名为build的目录，如果它不存在的话
rm -rf zlex/build
mkdir -p zlex/build

# 进入build目录
cd zlex/build

# 运行CMake以配置项目
cmake ..

# 编译项目
make zlex

# 运行项目（假设生成的可执行文件名为my_project）
./zlex
