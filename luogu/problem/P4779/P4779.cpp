#include <bits/stdc++.h>

using i64 = long long;

class Dijkstra {
public:
    int n;
    struct Edge {
        int to;
        i64 w;
    };
    std::vector<std::vector<Edge>> adj;

    std::vector<i64> dist;
    std::vector<int> pre;

    static constexpr i64 INF = LONG_LONG_MAX / 2;

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

        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>,std::greater<>> q;
        q.emplace(0, source);
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && vis[q.top().second]) {
                q.pop();
            }
            if (q.empty()) { break; }

            int u = q.top().second;
            q.pop();
            vis[u] = true;
            for (auto edge : adj[u]) {
                int to = edge.to;
                if (dist[to] > dist[u] + edge.w) {
                    dist[to] = dist[u] + edge.w;
                    pre[to] = u;
                    q.emplace(dist[to], to);
                }
            }
        }
    }
};

void solve() {
    int n, m, s;
    std::cin >> n >> m >> s;

    Dijkstra dijkstra(n);
    for (int i = 0, u, v, w; i < m; i++) {
        std::cin >> u >> v >> w;
        dijkstra.addEdge(u, v, w);
    }

    dijkstra.go(s);

    for (int i = 1; i <= n; i++) {
        std::cout << dijkstra.dist[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
