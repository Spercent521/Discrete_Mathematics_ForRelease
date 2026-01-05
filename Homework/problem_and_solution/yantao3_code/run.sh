#!/bin/bash
# 编译与运行脚本

echo "=========================================="
echo "C++ 算法编译和运行脚本"
echo "=========================================="

# 编译选项
COMPILER="g++"
CFLAGS="-std=c++17 -O2 -Wall"

# 输出目录
OUTPUT_DIR="./bin"
mkdir -p $OUTPUT_DIR

echo ""
echo "编译算法模块..."
echo "=========================================="

# 1. 编译Hierholzer与Fleury算法
echo "1. 编译 Hierholzer-Fleury 欧拉路径算法..."
$COMPILER $CFLAGS -o $OUTPUT_DIR/hierholzer_fleury hierholzer_fleury.cpp
if [ $? -eq 0 ]; then
    echo "   ✓ 编译成功"
else
    echo "   ✗ 编译失败"
fi

# 2. 编译Held-Karp算法
echo "2. 编译 Held-Karp 动态规划求解器..."
$COMPILER $CFLAGS -o $OUTPUT_DIR/held_karp held_karp.cpp -lm
if [ $? -eq 0 ]; then
    echo "   ✓ 编译成功"
else
    echo "   ✗ 编译失败"
fi

# 3. 编译Christofides算法
echo "3. 编译 Christofides 1.5-近似算法..."
$COMPILER $CFLAGS -o $OUTPUT_DIR/christofides christofides.cpp -lm
if [ $? -eq 0 ]; then
    echo "   ✓ 编译成功"
else
    echo "   ✗ 编译失败"
fi

# 4. 编译性能对比
echo "4. 编译 性能对比分析..."
$COMPILER $CFLAGS -o $OUTPUT_DIR/performance performance_comparison.cpp -lm
if [ $? -eq 0 ]; then
    echo "   ✓ 编译成功"
else
    echo "   ✗ 编译失败"
fi

echo ""
echo "运行程序..."
echo "=========================================="

echo ""
echo "【程序1】Hierholzer与Fleury欧拉路径算法"
echo "=========================================="
./$OUTPUT_DIR/hierholzer_fleury

echo ""
echo ""
echo "【程序2】Held-Karp动态规划TSP求解器"
echo "=========================================="
./$OUTPUT_DIR/held_karp

echo ""
echo ""
echo "【程序3】Christofides 1.5-近似算法"
echo "=========================================="
./$OUTPUT_DIR/christofides

echo ""
echo ""
echo "【程序4】性能对比分析"
echo "=========================================="
./$OUTPUT_DIR/performance

echo ""
echo "=========================================="
echo "所有程序运行完成！"
echo "=========================================="
