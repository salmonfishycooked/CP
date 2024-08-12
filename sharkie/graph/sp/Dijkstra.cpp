/**
 * 单源最短路径 (Single-Source Shortest Path)
 * Dijkstra - 堆优化版本
 * 采用邻接表存储图，结点编号为 1 ~ n
 * Notes: 不能处理负边权
 *
 * 时间复杂度: O(nlogn + m)，其中 n 为总顶点数，m 为总边数。
 *
 * 参数说明：
 * 1. dist[i] 代表源点到点 i 的最短距离
 * 2. pre 代表路径前驱。pre[i] 代表从源点到点 i 的最短路径中，点 i 的路径前驱结点编号。
 */

#include <bits/stdc++.h>

class Dijkstra {
public:
    static constexpr int INF = INT_MAX;

    int n;
    struct Edge {
        int to, weight;
    };
    std::vector<std::vector<Edge>> adj;

    std::vector<int> dist;
    std::vector<int> pre;

    explicit Dijkstra(int n) : n(n) {
        adj.assign(n + 1, {});
    }

    void addEdge(int from, int to, int weight) {
        adj[from].push_back({to, weight});
    }

    void go(int source) {
        dist.assign(n + 1, INF);
        pre.assign(n + 1, 0);

        std::vector<bool> vis(n + 1, false);
        dist[source] = 0;

        struct Node {
            int id, dis;
        };
        struct cmp {
            bool operator()(Node &a, Node &b) {
                return a.dis > b.dis;
            }
        };
        std::priority_queue<Node, std::vector<Node>, cmp> q;

        q.push({source, 0});
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && vis[q.top().id]) {
                q.pop();
            }
            if (q.empty()) { break; }

            int u = q.top().id;
            q.pop();
            vis[u] = true;
            for (auto edge : adj[u]) {
                int to = edge.to, weight = edge.weight;
                if (dist[u] + weight < dist[to]) {
                    dist[to] = dist[u] + weight;
                    pre[to] = u;
                    q.push({to, dist[to]});
                }
            }
        }
    }
};
