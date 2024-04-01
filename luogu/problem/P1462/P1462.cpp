#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using i64 = long long;

class Dijkstra {
public:
    struct Edge {
        i64 to, cost;
    };
    int n;
    std::vector<std::vector<Edge>> adj;
    std::vector<i64> f;
    std::vector<i64> dist;

    explicit Dijkstra(int _n) : n(_n) {
        adj.assign(n, {});
        f.resize(n);
    }

    void setFee(int u, i64 fee) {
        f[u] = fee;
    }

    void addEdge(int from, int to, i64 cost) {
        adj[from].push_back({to, cost});
    }

    void go(int source, i64 mxFee) {
        dist.assign(n, LONG_LONG_MAX);
        dist[source] = 0;
        if (f[source] > mxFee) {
            return;
        }

        std::vector<bool> vis(n, false);
        std::priority_queue<std::pair<i64, i64>, std::vector<std::pair<i64, i64>>, std::greater<>> q;
        q.emplace(0, source);
        while (!q.empty()) {
            while (!q.empty() && vis[q.top().second]) {
                q.pop();
            }
            if (q.empty()) {
                break;
            }

            auto [cost, from] = q.top();
            q.pop();
            vis[from] = true;

            for (auto &edge : adj[from]) {
                if (f[edge.to] > mxFee) {
                    continue;
                }
                if (cost + edge.cost < dist[edge.to]) {
                    dist[edge.to] = cost + edge.cost;
                    q.emplace(dist[edge.to], edge.to);
                }
            }
        }
    }
};

void solve() {
    int n, m, b;
    std::cin >> n >> m >> b;

    Dijkstra dijkstra(n);
    for (int i = 0; i < n; i++) {
        int fee;
        std::cin >> fee;
        dijkstra.setFee(i, fee);
    }

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        from--; to--;
        dijkstra.addEdge(from, to, cost);
        dijkstra.addEdge(to, from, cost);
    }

    int l = 0, r = 1e9 + 1;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        dijkstra.go(0, mid);
        if (dijkstra.dist[n - 1] > b) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (r == 1e9 + 1) {
        std::cout << "AFK" << '\n';
        return;
    }
    std::cout << r << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
