/**
 * 洛谷P3366 【模板】最小生成树
 * Prim 算法
 */

#include <bits/stdc++.h>

using i64 = int64_t;

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

void solve() {
    int N, M;
    std::cin >> N >> M;

    Prim prim(N);
    for (int i = 0, u, v, w; i < M; i++) {
        std::cin >> u >> v >> w;
        prim.addEdge(u, v, w);
        prim.addEdge(v, u, w);
    }

    bool connected = prim.go(1);
    if (!connected) {
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
