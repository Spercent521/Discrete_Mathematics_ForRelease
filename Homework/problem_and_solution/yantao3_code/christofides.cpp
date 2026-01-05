#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

/**
 * Christofides 算法实现
 * 旅行商问题的1.5-近似算法
 * 
 * 步骤：
 * 1. 构造最小生成树(MST)
 * 2. 找出所有奇度顶点
 * 3. 对奇度顶点求最小权完美匹配
 * 4. 合并MST和匹配得到欧拉图
 * 5. 求欧拉回路
 * 6. 使用短路策略从欧拉回路得到哈密尔顿回路
 */

class ChristofidsAlgorithm {
private:
    int n;
    vector<vector<double>> dist;
    vector<pair<int, int>> mst_edges;
    vector<vector<int>> adj;
    
    struct Edge {
        int u, v;
        double weight;
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };
    
    struct DSU {
        vector<int> parent, rank;
        
        DSU(int n) : parent(n), rank(n, 0) {
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        
        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
            return true;
        }
    };
    
public:
    ChristofidsAlgorithm(int num_cities) : n(num_cities) {
        dist.assign(n, vector<double>(n, 0));
        adj.assign(n, vector<int>());
    }
    
    void setDistance(int i, int j, double d) {
        dist[i][j] = d;
        dist[j][i] = d;
    }
    
    double euclideanDist(double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    
    void initFromCoordinates(const vector<pair<double, double>>& coords) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double d = euclideanDist(coords[i].first, coords[i].second,
                                        coords[j].first, coords[j].second);
                setDistance(i, j, d);
            }
        }
    }
    
    // 步骤1：使用Kruskal算法构造MST
    double buildMST() {
        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.push_back({i, j, dist[i][j]});
            }
        }
        
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        mst_edges.clear();
        adj.assign(n, vector<int>());
        
        double total_weight = 0;
        for (const auto& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                mst_edges.push_back({e.u, e.v});
                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
                total_weight += e.weight;
            }
        }
        
        return total_weight;
    }
    
    // 步骤2：找所有奇度顶点
    vector<int> findOddVertices() {
        vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() % 2 == 1) {
                odd.push_back(i);
            }
        }
        return odd;
    }
    
    // 步骤3：对奇度顶点求最小权完美匹配（贪心近似）
    vector<pair<int, int>> greedyMatching(const vector<int>& odd) {
        vector<pair<int, int>> matching;
        vector<bool> used(odd.size(), false);
        
        for (int i = 0; i < odd.size(); i++) {
            if (used[i]) continue;
            
            double min_dist = 1e9;
            int best_j = -1;
            
            for (int j = i + 1; j < odd.size(); j++) {
                if (used[j]) continue;
                if (dist[odd[i]][odd[j]] < min_dist) {
                    min_dist = dist[odd[i]][odd[j]];
                    best_j = j;
                }
            }
            
            if (best_j != -1) {
                matching.push_back({odd[i], odd[best_j]});
                used[i] = true;
                used[best_j] = true;
            }
        }
        
        return matching;
    }
    
    // 步骤4&5：构造欧拉图并求欧拉回路（Hierholzer算法）
    vector<int> getEulerianCircuit(const vector<pair<int, int>>& matching) {
        // 构造邻接表（包含MST和匹配边）
        vector<multiset<int>> graph(n);
        
        for (const auto& e : mst_edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        
        for (const auto& e : matching) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        
        // Hierholzer算法
        vector<int> circuit;
        vector<int> stack_seq;
        stack_seq.push_back(0);
        
        while (!stack_seq.empty()) {
            int u = stack_seq.back();
            if (!graph[u].empty()) {
                int v = *graph[u].begin();
                graph[u].erase(graph[u].find(v));
                graph[v].erase(graph[v].find(u));
                stack_seq.push_back(v);
            } else {
                circuit.push_back(u);
                stack_seq.pop_back();
            }
        }
        
        reverse(circuit.begin(), circuit.end());
        return circuit;
    }
    
    // 步骤6：使用短路策略从欧拉回路得到哈密尔顿回路
    vector<int> shortcutEulerianCircuit(const vector<int>& circuit) {
        vector<int> hamiltonian;
        vector<bool> visited(n, false);
        
        for (int v : circuit) {
            if (!visited[v]) {
                hamiltonian.push_back(v);
                visited[v] = true;
            }
        }
        
        return hamiltonian;
    }
    
    // 计算回路总长度
    double calculateTourLength(const vector<int>& tour) {
        double length = 0;
        for (int i = 0; i < tour.size(); i++) {
            int next = (i + 1) % tour.size();
            length += dist[tour[i]][tour[next]];
        }
        return length;
    }
    
    // 运行完整的Christofides算法
    pair<double, vector<int>> solve() {
        cout << "步骤1: 构造最小生成树..." << endl;
        double mst_weight = buildMST();
        cout << "  MST权值: " << fixed << setprecision(2) << mst_weight << endl;
        cout << "  MST边数: " << mst_edges.size() << endl;
        
        cout << "\n步骤2: 找奇度顶点..." << endl;
        vector<int> odd_vertices = findOddVertices();
        cout << "  奇度顶点: ";
        for (int v : odd_vertices) cout << v << " ";
        cout << "\n  奇度顶点数: " << odd_vertices.size() << endl;
        
        cout << "\n步骤3: 求最小权完美匹配..." << endl;
        auto matching = greedyMatching(odd_vertices);
        double matching_weight = 0;
        cout << "  匹配边: ";
        for (const auto& e : matching) {
            cout << "(" << e.first << "," << e.second << ") ";
            matching_weight += dist[e.first][e.second];
        }
        cout << "\n  匹配权值: " << matching_weight << endl;
        
        cout << "\n步骤4-5: 构造欧拉图并求欧拉回路..." << endl;
        vector<int> eulerian = getEulerianCircuit(matching);
        cout << "  欧拉回路长度: " << eulerian.size() << endl;
        
        cout << "\n步骤6: 短路策略得到哈密尔顿回路..." << endl;
        vector<int> hamiltonian = shortcutEulerianCircuit(eulerian);
        double tour_length = calculateTourLength(hamiltonian);
        
        cout << "  最终回路长度: " << tour_length << endl;
        cout << "  理论上界（1.5 * OPT）: " << 1.5 * mst_weight << endl;
        
        return {tour_length, hamiltonian};
    }
    
    void printDistMatrix() {
        cout << "距离矩阵:" << endl;
        cout << fixed << setprecision(1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(8) << dist[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "========== Christofides 算法演示 ==========" << endl;
    
    // 测试案例：6城市
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
    
    ChristofidsAlgorithm solver(coords.size());
    solver.initFromCoordinates(coords);
    
    cout << endl;
    solver.printDistMatrix();
    
    cout << "\n================== 执行Christofides算法 ==================\n" << endl;
    
    auto [tour_length, tour] = solver.solve();
    
    cout << "\n================== 最终结果 ==================\n" << endl;
    cout << fixed << setprecision(2);
    cout << "旅行商最优回路长度: " << tour_length << endl;
    cout << "旅行路线: ";
    for (int i = 0; i < tour.size(); i++) {
        cout << cityNames[tour[i]];
        if (i < tour.size() - 1) cout << " -> ";
    }
    cout << " -> " << cityNames[tour[0]] << endl;
    
    cout << "\nChristofides算法保证: 解的长度 ≤ 1.5 × OPT" << endl;
    
    return 0;
}
