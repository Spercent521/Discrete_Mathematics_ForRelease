#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

/**
 * Held-Karp 动态规划算法
 * 解决旅行商问题(TSP)的精确算法
 * 时间复杂度: O(n^2 * 2^n)
 * 空间复杂度: O(n * 2^n)
 */

class TSPSolver {
private:
    int n;
    vector<vector<double>> dist;
    vector<vector<double>> dp;
    vector<vector<int>> parent;
    
public:
    TSPSolver(int num_cities) : n(num_cities) {
        dist.assign(n, vector<double>(n, 0));
        dp.assign(n, vector<double>(1 << n, 1e9));
        parent.assign(n, vector<int>(1 << n, -1));
    }
    
    // 设置城市间距离
    void setDistance(int i, int j, double d) {
        dist[i][j] = d;
        dist[j][i] = d;
    }
    
    // 欧几里得距离
    double euclideanDist(double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    
    // 从坐标初始化距离矩阵
    void initFromCoordinates(const vector<pair<double, double>>& coords) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double d = euclideanDist(coords[i].first, coords[i].second,
                                        coords[j].first, coords[j].second);
                setDistance(i, j, d);
            }
        }
    }
    
    // Held-Karp 动态规划
    double solveTSP() {
        // dp[i][mask] = 从城市0出发，访问过mask中的城市，最后到达城市i的最短距离
        
        // 初始化：仅访问城市0和城市i的情况
        for (int i = 1; i < n; i++) {
            dp[i][1 | (1 << i)] = dist[0][i];
        }
        
        // 遍历所有子集
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;  // i不在mask中
                if (dp[i][mask] >= 1e9) continue; // 不可达
                
                // 尝试从i出发到j
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue; // j已在mask中
                    
                    int newMask = mask | (1 << j);
                    double newDist = dp[i][mask] + dist[i][j];
                    
                    if (newDist < dp[j][newMask]) {
                        dp[j][newMask] = newDist;
                        parent[j][newMask] = i;
                    }
                }
            }
        }
        
        // 计算最终答案：访问所有城市后回到城市0
        double ans = 1e9;
        int fullMask = (1 << n) - 1;
        
        for (int i = 1; i < n; i++) {
            double cost = dp[i][fullMask] + dist[i][0];
            ans = min(ans, cost);
        }
        
        return ans;
    }
    
    // 重建最优路径
    vector<int> reconstructPath() {
        vector<int> path;
        int fullMask = (1 << n) - 1;
        
        // 找到最后一个城市
        int last = 1;
        double best = 1e9;
        for (int i = 1; i < n; i++) {
            if (dp[i][fullMask] + dist[i][0] < best) {
                best = dp[i][fullMask] + dist[i][0];
                last = i;
            }
        }
        
        // 回溯
        int mask = fullMask;
        int current = last;
        path.push_back(current);
        
        while (current != 0) {
            int prev = parent[current][mask];
            path.push_back(prev);
            mask ^= (1 << current);
            current = prev;
        }
        
        reverse(path.begin(), path.end());
        return path;
    }
    
    void printDistMatrix() {
        cout << "距离矩阵:" << endl;
        cout << fixed << setprecision(2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(8) << dist[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "========== Held-Karp 动态规划求解TSP ==========" << endl;
    
    // 测试案例：6个城市
    cout << "\n测试案例：6城市TSP" << endl;
    cout << "城市坐标:" << endl;
    vector<pair<double, double>> coords = {
        {0, 0},    // A
        {1, 3},    // B
        {4, 1},    // C
        {5, 4},    // D
        {7, 2},    // E
        {3, 6}     // F
    };
    
    vector<string> cityNames = {"A", "B", "C", "D", "E", "F"};
    
    for (int i = 0; i < coords.size(); i++) {
        cout << cityNames[i] << ": (" << coords[i].first << ", " << coords[i].second << ")" << endl;
    }
    
    TSPSolver solver(coords.size());
    solver.initFromCoordinates(coords);
    
    cout << endl;
    solver.printDistMatrix();
    
    cout << "\nSolving TSP with Held-Karp algorithm..." << endl;
    double minCost = solver.solveTSP();
    vector<int> path = solver.reconstructPath();
    
    cout << fixed << setprecision(2);
    cout << "\n最优费用: " << minCost << endl;
    cout << "最优路径: ";
    for (int i = 0; i < path.size(); i++) {
        cout << cityNames[path[i]];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << " -> " << cityNames[path[0]] << endl;
    
    // 测试案例2：5个城市，随机距离矩阵
    cout << "\n========== 测试案例2：5城市TSP ==========" << endl;
    TSPSolver solver2(5);
    
    // 对称距离矩阵
    double distMatrix[5][5] = {
        {0,   10,  15,  20,  25},
        {10,  0,   35,  25,  30},
        {15,  35,  0,   30,  20},
        {20,  25,  30,  0,   15},
        {25,  30,  20,  15,  0}
    };
    
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            solver2.setDistance(i, j, distMatrix[i][j]);
        }
    }
    
    cout << "距离矩阵:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(6) << (int)distMatrix[i][j];
        }
        cout << endl;
    }
    
    double minCost2 = solver2.solveTSP();
    vector<int> path2 = solver2.reconstructPath();
    
    cout << "\n最优费用: " << minCost2 << endl;
    cout << "最优路径: ";
    for (int i = 0; i < path2.size(); i++) {
        cout << path2[i];
        if (i < path2.size() - 1) cout << " -> ";
    }
    cout << " -> " << path2[0] << endl;
    
    return 0;
}
