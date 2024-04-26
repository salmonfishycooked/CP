/**
 * 洛谷P3366 【模板】最小生成树
 * Kruskal 算法
 */

#include <bits/stdc++.h>

using i64 = int64_t;

class UnionFind {
public:
    int n;
    std::vector<int> fa;

    explicit UnionFind(int _n) : n(_n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }

    void _union(int u, int v) {
        int uFa = find(u), vFa = find(v);
        fa[vFa] = uFa;
    }

    int find(int u) {
        if (fa[u] != u) {
            return fa[u] = find(fa[u]);
        }
        return u;
    }
};

template <typename T = int>
class Kruskal {
public:
    struct Edge {
        int from, to;
        T weight;
    };
    int n;
    std::vector<Edge> edges;

    explicit Kruskal(int _n) : n(_n) {}

    void addEdge(int from, int to, T weight) {
        edges.push_back({from, to, weight});
    }

    T go() {
        UnionFind uf(n);

        std::sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b) -> bool {
            return a.weight < b.weight;
        });

        int cnt = 0;
        T sum = 0;
        for (auto edge : edges) {
            int from = edge.from, to = edge.to, weight = edge.weight;
            if (uf.find(from) != uf.find(to)) {
                uf._union(from, to);
                sum += weight;
                cnt += 1;
            }
            if (cnt == n - 1) {
                break;
            }
        }

        return cnt == n - 1 ? sum : -1;
    }
};

void solve() {
    int N, M;
    std::cin >> N >> M;

    Kruskal kruskal(N);
    for (int i = 0, u, v, w; i < M; i++) {
        std::cin >> u >> v >> w;
        kruskal.addEdge(u, v, w);
        kruskal.addEdge(v, u, w);
    }

    int res = kruskal.go();
    if (res == -1) {
        std::cout << "orz" << '\n';
        return;
    }
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
