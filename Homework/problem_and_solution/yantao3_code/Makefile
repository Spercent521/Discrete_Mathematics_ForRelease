# Makefile for TSP Algorithms

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
LDFLAGS = -lm

# 目标文件
TARGETS = hierholzer_fleury held_karp christofides performance_comparison

# 输出目录
BIN_DIR = bin

# 默认目标
all: $(TARGETS)

# 创建输出目录
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# 欧拉图算法
hierholzer_fleury: hierholzer_fleury.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$@ $<

# Held-Karp算法
held_karp: held_karp.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$@ $< $(LDFLAGS)

# Christofides算法
christofides: christofides.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$@ $< $(LDFLAGS)

# 性能对比
performance_comparison: performance_comparison.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$@ $< $(LDFLAGS)

# 运行所有程序
run: all
	@echo "=========================================="
	@echo "【程序1】欧拉路径算法"
	@echo "=========================================="
	@./$(BIN_DIR)/hierholzer_fleury
	@echo ""
	@echo ""
	@echo "=========================================="
	@echo "【程序2】Held-Karp动态规划TSP求解"
	@echo "=========================================="
	@./$(BIN_DIR)/held_karp
	@echo ""
	@echo ""
	@echo "=========================================="
	@echo "【程序3】Christofides算法"
	@echo "=========================================="
	@./$(BIN_DIR)/christofides
	@echo ""
	@echo ""
	@echo "=========================================="
	@echo "【程序4】性能对比分析"
	@echo "=========================================="
	@./$(BIN_DIR)/performance_comparison

# 清理
clean:
	rm -rf $(BIN_DIR)

# 帮助
help:
	@echo "可用命令："
	@echo "  make              - 编译所有程序"
	@echo "  make run          - 编译并运行所有程序"
	@echo "  make clean        - 删除编译产物"
	@echo "  make help         - 显示此帮助信息"
	@echo ""
	@echo "单独编译:"
	@echo "  make hierholzer_fleury    - 编译欧拉算法"
	@echo "  make held_karp            - 编译Held-Karp"
	@echo "  make christofides         - 编译Christofides"
	@echo "  make performance_comparison - 编译性能对比"

.PHONY: all run clean help
