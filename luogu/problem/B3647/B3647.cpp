#include <bits/stdc++.h>

using i64 = int64_t;

class Floyd {
public:
    int n;

    constexpr static i64 INF = LONG_LONG_MAX / 2;

    std::vector<std::vector<i64>> mat;

    std::vector<std::vector<i64>> dist;

    explicit Floyd(int _n) : n(_n) {
        mat.assign(n + 1, std::vector<i64>(n + 1, INF));
        dist.assign(n + 1, std::vector<i64>(n + 1));
        for (int i = 1; i <= n; i++) {
            mat[i][i] = 0;
        }
    };

    void addEdge(int u, int v, i64 weight) {
        mat[u][v] = std::min(mat[u][v], weight);
    }

    void go() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = mat[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    dist[j][k] = std::min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    Floyd floyd(n);
    for (int i = 0, u, v, w; i < m; i++) {
        std::cin >> u >> v >> w;
        floyd.addEdge(u, v, w);
        floyd.addEdge(v, u, w);
    }

    floyd.go();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << floyd.dist[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
