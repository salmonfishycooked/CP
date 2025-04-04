/**
 * 最大流 - EK 算法
 * 节点编号：1 ~ n
 * 边采用链式前向星存储
 *
 * 方法说明：
 * 1. void addEdge(int u, int v, int w)，添加(u, v)有向边且最大流量为w，同时添加其反向边。
 * 2. int go(int s, int t)，返回从源点s与汇点t所形成的网络流的最大流量。
 *
 * 时间复杂度：O(|V||E|^2)，其中|V|为点集的基数，|E|为边集的基数。
 */

#include <bits/stdc++.h>

using i64 = long long;

class EK {
public:
    static constexpr int NULLPTR = -1;
    struct Edge { int to, next, cap, flow; };

    int n;
    std::vector<Edge> edges;
    std::vector<int> head;

    EK(int n) : n(n) { head.assign(n + 1, NULLPTR); }

    void addEdge(int u, int v, int w) {
        edges.push_back({v, head[u], w, 0});
        head[u] = edges.size() - 1;
        edges.push_back({u, head[v], 0, 0});
        head[v] = edges.size() - 1;
    }

    int go(int s, int t) {
        std::vector<int> pre(n + 1);
        auto bfs = [&]() -> bool {
            std::vector<bool> vis(n + 1);
            std::queue<int> q;
            q.push(s);
            vis[s] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int edgeId = head[u]; edgeId != NULLPTR; edgeId = edges[edgeId].next) {
                    int to = edges[edgeId].to;
                    if (vis[to] || edges[edgeId].cap == edges[edgeId].flow) { continue; }
                    q.push(to);
                    vis[to] = true;
                    pre[to] = edgeId;
                    if (to == t) { return true; }
                }
            }

            return false;
        };

        int mxFlow = 0;
        while (bfs()) {
            int mnFlow = INT_MAX;
            for (int cur = t; cur != s; cur = edges[pre[cur] ^ 1].to) {
                mnFlow = std::min(mnFlow, edges[pre[cur]].cap - edges[pre[cur]].flow);
            }
            mxFlow += mnFlow;

            for (int cur = t; cur != s; cur = edges[pre[cur] ^ 1].to) {
                edges[pre[cur]].flow += mnFlow;
                edges[pre[cur] ^ 1].flow -= mnFlow;
            }
        }

        return mxFlow;
    }
};