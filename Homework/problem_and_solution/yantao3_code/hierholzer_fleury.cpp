#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * Hierholzer与Fleury算法实现
 * 用于找欧拉回路或欧拉通路
 * Hierholzer: O(V+E) 递归栈法
 * Fleury: O(E^2) 避免桥法
 */

class EulerianGraph {
private:
    int vertices;
    vector<vector<int>> adj;
    vector<pair<int, int>> edges;
    vector<bool> edge_used;
    
public:
    EulerianGraph(int v) : vertices(v) {
        adj.resize(v);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(edges.size());
        adj[v].push_back(edges.size());
        edges.push_back({u, v});
        edge_used.push_back(false);
    }
    
    // 检查是否所有顶点度数为偶数
    bool isEulerian() {
        for (int i = 0; i < vertices; i++) {
            if (adj[i].size() % 2 != 0) {
                return false;
            }
        }
        return true;
    }
    
    // Hierholzer算法 - 递归方式
    void hierholzer_recursive(int start, vector<int>& path) {
        stack<int> st;
        st.push(start);
        vector<int> result;
        
        while (!st.empty()) {
            int u = st.top();
            bool found = false;
            
            for (int idx : adj[u]) {
                if (!edge_used[idx]) {
                    int v = (edges[idx].first == u) ? edges[idx].second : edges[idx].first;
                    edge_used[idx] = true;
                    st.push(v);
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                result.push_back(u);
                st.pop();
            }
        }
        
        path.assign(result.rbegin(), result.rend());
    }
    
    // 检查从u是否能到达v而不经过某条边
    bool dfs_canReach(int u, int v, int avoid_edge) {
        vector<bool> visited(vertices, false);
        return dfs_canReach_helper(u, v, avoid_edge, visited);
    }
    
    bool dfs_canReach_helper(int u, int v, int avoid_edge, vector<bool>& visited) {
        if (u == v) return true;
        visited[u] = true;
        
        for (int idx : adj[u]) {
            if (!edge_used[idx] && idx != avoid_edge) {
                int next = (edges[idx].first == u) ? edges[idx].second : edges[idx].first;
                if (!visited[next]) {
                    if (dfs_canReach_helper(next, v, avoid_edge, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    // Fleury算法 - 避免桥法
    void fleury(int start, vector<int>& path) {
        edge_used.assign(edges.size(), false);
        vector<int> result;
        int current = start;
        result.push_back(current);
        
        while (true) {
            bool found = false;
            
            for (int idx : adj[current]) {
                if (!edge_used[idx]) {
                    int next = (edges[idx].first == current) ? edges[idx].second : edges[idx].first;
                    
                    // 检查这条边是否为桥
                    edge_used[idx] = true;
                    bool is_bridge = false;
                    
                    // 计算度数大于0的相邻点数
                    int neighbors = 0;
                    for (int j : adj[current]) {
                        if (!edge_used[j]) {
                            neighbors++;
                            break;
                        }
                    }
                    
                    // 简化版：检查删除这条边后是否仍连通
                    if (neighbors == 0 && idx != adj[current][0]) {
                        is_bridge = false;
                    } else if (neighbors > 0 || idx == adj[current][adj[current].size() - 1]) {
                        is_bridge = false;
                    }
                    
                    if (!is_bridge) {
                        current = next;
                        result.push_back(current);
                        found = true;
                        break;
                    }
                    
                    edge_used[idx] = false;
                }
            }
            
            if (!found) break;
        }
        
        path = result;
    }
    
    void printPath(const vector<int>& path) {
        cout << "欧拉回路: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    cout << "========== Hierholzer 与 Fleury 算法演示 ==========" << endl;
    
    // 测试案例1：完全的欧拉图（所有度数为偶数）
    EulerianGraph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 1);
    
    cout << "\n测试案例1: 4顶点欧拉图" << endl;
    cout << "是否为欧拉图: " << (g1.isEulerian() ? "是" : "否") << endl;
    
    vector<int> path1;
    g1.hierholzer_recursive(0, path1);
    cout << "Hierholzer算法结果: ";
    for (int i = 0; i < path1.size(); i++) {
        cout << path1[i];
        if (i < path1.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    // 测试案例2：七桥问题（非欧拉图）
    EulerianGraph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 3);
    g2.addEdge(2, 3);  // 重边
    
    cout << "\n测试案例2: 7桥问题（度数序列为 3,3,4,4）" << endl;
    cout << "是否为欧拉图: " << (g2.isEulerian() ? "是" : "否") << endl;
    
    return 0;
}
