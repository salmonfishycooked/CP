/**
 * 最小生成树 (Minimal Spanning Tree)
 * Prim 算法 - 堆优化版本
 * 节点编号：1 ~ n
 *
 * 方法说明：
 * 1. bool go(int source) 以 source 为源点开始 Prim 算法，返回 true 代表原图连通，false 代表不连通
 *
 * 参数说明：
 * 1. sum 代表 Prim 算法正确结束后（也就是原图连通），对应的最小生成树的所有边权之和
 *
 * 模板 template <typename T = int> 代表边权采用什么类型存储，默认为 int
 *
 * 时间复杂度: O(mlogn), 其中 n 为总点数， m 为总边数。
 */

#include <bits/stdc++.h>

template <typename T = int>
class Prim {
public:
    static constexpr int INF = INT_MAX;

    struct Edge {
        int to;
        T weight;
    };
    int n;
    std::vector<std::vector<Edge>> adj;

    T sum;

    explicit Prim(int _n) : n(_n) {
        adj.assign(n + 1, {});
    }

    void addEdge(int from, int to, T weight) {
        adj[from].push_back({to, weight});
    }

    bool go(int source) {
        sum = 0;
        std::vector<T> dis(n + 1, INF);
        dis[source] = 0;

        std::vector<bool> vis(n + 1);
        struct Node {
            int id, weight;
            bool operator< (const Node &a) const { return weight > a.weight; }
        };
        std::priority_queue<Node> q;
        q.push({1, 0});
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && vis[q.top().id]) {
                q.pop();
            }
            if (q.empty()) {
                return false;
            }

            int id = q.top().id;
            sum += q.top().weight;
            q.pop();
            vis[id] = true;
            for (auto edge : adj[id]) {
                int to = edge.to, weight = edge.weight;
                if (vis[to] || dis[to] < weight) { continue; }
                dis[to] = weight;
                q.push({to, weight});
            }
        }

        return true;
    }
};
