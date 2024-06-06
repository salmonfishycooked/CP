/**
 * 洛谷P3366 【模板】最小生成树
 * Prim 算法
 */

#include <bits/stdc++.h>

using i64 = int64_t;

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

void solve() {
    int n, m;
    std::cin >> n >> m;

    Prim prim(n);
    for (int i = 0, u, v, w; i < m; i++) {
        std::cin >> u >> v >> w;
        prim.addEdge(u, v, w);
        prim.addEdge(v, u, w);
    }

    if (!prim.go(1)) {
        std::cout << "orz" << '\n';
        return;
    }
    std::cout << prim.sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
