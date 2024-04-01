// 最小生成树 (Minimal Spanning Tree)
// Prim - 堆优化版本
// 采用邻接表存储图，结点编号为 1 ~ n
// 时间复杂度: O(nlogn + m), 其中 n 为总顶点数，m 为总边数。

// 1. closest 数组存的是点与点之间的边
// 2. lowCost 数组存的是 closest 对应边的权值
// 例如 closest[2] = 7, lowCost[2] = 23. 说明在 2-7 的边中权值为 23 的边是生成树的边。
// 3. prim 函数返回 false 代表原图不连通。

#include <bits/stdc++.h>

constexpr int INF = INT_MAX;

struct PrimHeap {
    int n;

    struct Edge {
        int to, weight;
    };
    std::vector<std::vector<Edge>> adj;

    std::vector<int> closest;
    std::vector<int> lowCost;

    PrimHeap(int n) {
        this->n = n;
        adj.assign(n + 1, {});
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
    }

    bool prim(int source) {
        closest.assign(n + 1, 0);
        lowCost.assign(n + 1, INF);

        lowCost[source] = 0;
        std::vector<bool> vis(n + 1, false);

        struct Node {
            int id, cost;
        };
        struct cmp {
            bool operator()(Node &a, Node &b) {
                return a.cost > b.cost;
            }
        };
        std::priority_queue<Node, std::vector<Node>, cmp> q;
        q.push({source, 0});

        for (int i = 1; i <= n; i++) {
            while (!q.empty() && vis[q.top().id]) {
                q.pop();
            }
            if (q.empty()) {
                return false;
            }
            int u = q.top().id;
            vis[u] = true;
            for (int j = 0; j < adj[u].size(); j++) {
                int to = adj[u][j].to, w = adj[u][j].weight;
                if (!vis[to] && w < lowCost[to]) {
                    lowCost[to] = w;
                    closest[to] = u;
                    q.push({to, w});
                }
            }
        }
        return true;
    }
};
