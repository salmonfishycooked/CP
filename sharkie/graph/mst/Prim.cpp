/**
 * 最小生成树 (Minimum Spanning Tree)
 * Prim 算法 - 堆优化版本
 * 节点编号：1 ~ n
 *
 * 方法说明：
 * 1. bool go(int source) 以 source 为源点开始 Prim 算法，返回 true 代表原图连通，false 代表不连通
 *
 * 参数说明：
 * 1. sum 代表 Prim 算法正确结束后（也就是原图连通），对应的最小生成树的所有边权之和
 *
 * 时间复杂度: O(mlogn)。其中 n 为总点数，m 为总边数。
 */

#include <bits/stdc++.h>

using i64 = long long;

class Prim {
public:
    int n;

    static constexpr int INF = INT_MAX;

    struct Edge {
        int to, w;
    };
    std::vector<std::vector<Edge>> adj;

    i64 sum;

    explicit Prim(int _n) : n(_n) {
        adj.assign(n + 1, {});
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    bool go(int source) {
        sum = 0;

        std::vector<int> dist(n + 1, INF);
        std::vector<bool> vis(n + 1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
        q.emplace(0, 1);
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && vis[q.top().second]) {
                q.pop();
            }
            if (q.empty()) { return false; }

            auto [dis, u] = q.top();
            q.pop();
            sum += dis;
            vis[u] = true;

            for (auto [v, w] : adj[u]) {
                if (vis[v] || dist[v] <= w) { continue; }
                dist[v] = w;
                q.emplace(w, v);
            }
        }

        return true;
    }
};
