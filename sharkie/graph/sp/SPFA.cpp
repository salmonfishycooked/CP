/**
 * 单源最短路径 (Single-Source Shortest Path)
 * SPFA - Bellman Ford 算法的队列优化版
 * 采用邻接表存储图，结点编号为 1 ~ n
 *
 * 时间复杂度: O(nm)，其中 n 为总顶点数， m 为总边数。但在稀疏图上运行效率较高，为 O(km)，其中 k 是一个较小的常数。
 *
 * 参数说明：
 * 1. dist[i] 代表源点到点 i 的最短距离
 *
 * 方法说明：
 * 1. bool go()，执行算法，返回 true 则代表图中有负环，false 则无负环。
 */

#include <bits/stdc++.h>

using i64 = long long;

class SPFA {
public:
    struct Edge {
        int u;
        i64 w;
    };

    int n;
    std::vector<std::vector<Edge>> adj;

    std::vector<i64> dist;

    constexpr static i64 INF = LONG_LONG_MAX / 2;

    explicit SPFA(int n) : n(n) {
        adj.resize(n + 1);
    }

    void addEdge(int u, int v, i64 w) {
        adj[u].push_back({v, w});
    }

    bool go(int source) {
        dist.assign(n + 1, INF);
        dist[source] = 0;
        std::vector<bool> inQueue(n + 1);
        std::vector<int> cnt(n + 1);

        std::queue<int> q;
        q.push(source);
        inQueue[source] = true;
        cnt[source] += 1;
        while (!q.empty()) {
            int u = q.front();
            inQueue[u] = false;
            q.pop();

            for (const auto &edge : adj[u]) {
                int to = edge.u;
                if (dist[to] > dist[u] + edge.w) {
                    dist[to] = dist[u] + edge.w;
                    if (!inQueue[to]) {
                        cnt[to] += 1;
                        if (cnt[to] >= n) {
                            return true;
                        }
                        inQueue[to] = true;
                        q.push(to);
                    }
                }
            }
        }

        return false;
    }
};
