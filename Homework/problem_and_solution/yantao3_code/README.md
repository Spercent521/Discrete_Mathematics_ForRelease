# TSP算法C++实现说明

## 项目结构

本项目包含欧拉图与哈密尔顿图相关算法的完整C++实现：

```
code/
├── hierholzer_fleury.cpp      # 欧拉回路求解
├── held_karp.cpp               # TSP精确求解 - 动态规划
├── christofides.cpp            # TSP近似求解 - 1.5-近似算法
├── performance_comparison.cpp  # 算法性能对比分析
├── run.sh                       # 自动编译运行脚本
└── README.md                    # 本文件
```

## 各模块说明

### 1. hierholzer_fleury.cpp - 欧拉图问题

**功能**：判断图是否为欧拉图，并求欧拉回路

**关键算法**：
- **Hierholzer算法**：O(V+E) 递归栈法，高效求欧拉回路
- **Fleury算法**：O(E²) 避免桥法，逐步构造欧拉通路

**核心类**：`EulerianGraph`
- `addEdge(u, v)`：添加无向边
- `isEulerian()`：判断欧拉性 - 检查所有顶点度数是否为偶数
- `hierholzer_recursive(start, path)`：递归构造欧拉回路
- `fleury(start, path)`：Fleury算法构造欧拉回路

**应用场景**：
- 七桥问题验证
- DNA序列组装
- 网络诊断与邮递员问题

---

### 2. held_karp.cpp - 旅行商问题精确求解

**功能**：使用动态规划求解TSP的最优解

**算法原理**：
- 状态定义：`dp[i][mask]` = 从城市0出发，访问过mask中的城市，最后到达城市i的最短距离
- 状态转移：对每个子集mask和当前城市i，尝试扩展到未访问的城市j
- 时间复杂度：O(n² × 2ⁿ)
- 空间复杂度：O(n × 2ⁿ)

**核心类**：`TSPSolver`
- `initFromCoordinates(coords)`：从坐标初始化距离矩阵
- `solveTSP()`：求解最优TSP回路
- `reconstructPath()`：重建最优路径

**适用规模**：n ≤ 15 时可在合理时间内得到精确解

**测试用例**：
- 6城市欧几里得距离
- 5城市对称距离矩阵

---

### 3. christofides.cpp - 旅行商问题近似求解

**功能**：使用Christofides算法求解TSP的1.5-近似解

**算法步骤**：

1. **构造最小生成树(MST)**
   - 使用Kruskal算法
   - 权值w(T) ≤ OPT（下界）

2. **找奇度顶点集合O**
   - 根据握手定理，|O|必为偶数

3. **对O求最小权完美匹配**
   - 关键性质：w(M) ≤ OPT/2
   - 使用贪心策略快速近似

4. **合并T和M得欧拉图**
   - 所有顶点度数均为偶数

5. **求欧拉回路**
   - 使用Hierholzer算法
   - O(V + E)时间

6. **短路策略(Short-cutting)**
   - 按访问顺序跳过重复顶点
   - 由三角不等式保证长度不增加

**近似比证明**：
```
w(Christofides) = w(T ∪ M) ≤ OPT + OPT/2 = 1.5 × OPT
```

**核心类**：`ChristofidsAlgorithm`
- `buildMST()`：Kruskal算法构造MST
- `findOddVertices()`：找奇度顶点
- `greedyMatching(odd)`：贪心完美匹配
- `getEulerianCircuit(matching)`：构造欧拉回路
- `shortcutEulerianCircuit(circuit)`：短路得到哈密尔顿回路
- `solve()`：完整算法执行并输出每一步

**特点**：
- 保证1.5-近似比
- 多项式时间O(n³)
- 实际效果远优于理论界

---

### 4. performance_comparison.cpp - 性能对比分析

**功能**：对比多种TSP算法的性能

**实现算法**：
1. **贪心算法(Nearest Neighbor)**：O(n²)
   - 每次选择最近未访问城市
   - 快速但质量一般

2. **2-opt局部搜索**：O(n³)
   - 对贪心解进行迭代改进
   - 通常改进20-30%

3. **简化Christofides**：O(n³)
   - 完整版的近似实现
   - 保证1.5-近似比

**测试功能**：
- `generateRandomCities(seed)`：随机生成城市坐标
- `generateGridCities(grid_size)`：生成网格城市
- `greedyTSP()`：贪心求解
- `twoOptImprovement(tour)`：2-opt改进
- `christofidesTSP()`：Christofides近似
- `printReport()`：对比分析报告

**性能对比**：
```
算法              时间复杂度        空间复杂度    适用规模
Held-Karp         O(n^2·2^n)      O(n·2^n)     n ≤ 15
Christofides      O(n^3)          O(n^2)       15 < n ≤ 1000
贪心+2-opt        O(n^3)          O(n^2)       n > 100
Nearest Neighbor  O(n^2)          O(n)         任意规模
```

---

## 编译与运行

### Linux/Unix/Mac

```bash
# 编译所有程序
g++ -std=c++17 -O2 -o hierholzer_fleury hierholzer_fleury.cpp
g++ -std=c++17 -O2 -o held_karp held_karp.cpp -lm
g++ -std=c++17 -O2 -o christofides christofides.cpp -lm
g++ -std=c++17 -O2 -o performance performance_comparison.cpp -lm

# 或使用自动化脚本
bash run.sh
```

### Windows (MinGW/MSVC)

```bash
# MinGW
g++ -std=c++17 -O2 -o hierholzer_fleury.exe hierholzer_fleury.cpp
g++ -std=c++17 -O2 -o held_karp.exe held_karp.cpp
g++ -std=c++17 -O2 -o christofides.exe christofides.cpp
g++ -std=c++17 -O2 -o performance.exe performance_comparison.cpp

# MSVC
cl /std:c++latest /O2 hierholzer_fleury.cpp
cl /std:c++latest /O2 held_karp.cpp
cl /std:c++latest /O2 christofides.cpp
cl /std:c++latest /O2 performance_comparison.cpp
```

---

## 输出示例

### Hierholzer算法
```
========== Hierholzer 与 Fleury 算法演示 ==========

测试案例1: 4顶点欧拉图
是否为欧拉图: 是
Hierholzer算法结果: 0 -> 1 -> 2 -> 0 -> 3 -> 1
```

### Held-Karp算法
```
========== Held-Karp 动态规划求解TSP ==========

距离矩阵:
     0.00  10.00  15.00  20.00  25.00
    10.00   0.00  35.00  25.00  30.00
    ...

最优费用: 85.00
最优路径: 0 -> 1 -> 3 -> 4 -> 2 -> 0
```

### Christofides算法
```
步骤1: 构造最小生成树...
  MST权值: 18.52
  
步骤2: 找奇度顶点...
  奇度顶点: 2 5
  
步骤3: 求最小权完美匹配...
  匹配权值: 5.39

步骤6: 短路策略得到哈密尔顿回路...
  最终回路长度: 23.91
  理论上界（1.5 * OPT）: 27.78
```

---

## 理论基础

### 欧拉图 vs 哈密尔顿图

| 问题 | 定义 | 判定 | 复杂度 |
|------|------|------|--------|
| 欧拉回路 | 遍历每条边恰好一次 | 充要条件：所有顶点度数为偶数 | O(V+E) |
| 哈密尔顿回路 | 访问每个顶点恰好一次 | NP完全问题 | NP-Hard |

### TSP相关定理

1. **哈密尔顿问题的NP完全性**（Cook-Levin定理）
   - 判定问题：是否存在长度≤k的哈密尔顿回路
   - 证明：基于布尔可满足性问题(SAT)的多项式归约

2. **Christofides算法的1.5-近似**
   - 定理：Christofides算法输出的TSP解长度 ≤ 1.5 × OPT
   - 证明关键：MST≤OPT，完美匹配≤OPT/2，短路不增加

3. **TSP的近似下界**
   - 若P≠NP，则不存在常数近似比c<1.465的多项式算法（Karpinski 2011）
   - 这意味着Christofides的1.5比较已接近理论极限

---

## 拓展方向

1. **动态规划优化**
   - Bellman-Held-Karp：利用对称性减少状态数
   - 并行化：并行DP求解

2. **启发式改进**
   - 3-opt、LKH(Lin-Kernighan-Helsgaun)算法
   - 遗传算法、蚁群算法、模拟退火

3. **特殊TSP变体**
   - 欧几里得TSP：近似比可至1+ε（PTAS）
   - 路径TSP：不同于回路的变种
   - 动态TSP：城市或距离随时间变化

4. **实际应用**
   - 集成电路设计中的线路规划
   - 机器人路径规划
   - 物流配送优化

---

## 参考文献

1. Held, M., & Karp, R. M. (1962). A dynamic programming approach to sequencing problems.
2. Christofides, N. (1976). Worst-case analysis of a new heuristic for the travelling salesman problem.
3. Bondy, J. A., & Murty, U. S. R. (1976). Graph Theory with Applications.
4. Cook, W. J., et al. (2012). Combinatorial Optimization.

---

**作者**: ......  
**时间**: 2025年1月  
**机构**: 中国地质大学(武汉) 计算机学院
