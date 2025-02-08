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

class Solution {
public:
    void solve(int round) {
        int n, m;
        std::cin >> n >> m;

        EK ek(n);
        for (int i = 0, u, v, w; i < m; i++) {
            std::cin >> u >> v >> w;
            ek.addEdge(u, v, w);
        }

        std::cout << "Case " << round << ": " << ek.go(1, n) << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    for (int i = 1; i <= t; i++) { s.solve(i); }

    return 0;
}
