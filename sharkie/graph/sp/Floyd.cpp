/**
 * 多源最短路径 (Multi-Source Shortest Path)
 * Floyd
 * 采用邻接矩阵存储图，结点编号为 1 ~ n
 * 时间复杂度: O(n^3)，其中 n 为总顶点数。
 *
 * 参数说明：
 * 1. dist[i] 代表从源点 i 开始到每个点的最短距离。dist[i][j] 代表源点 i 到点 j 的最短距离。
 */

#include <bits/stdc++.h>

using i64 = long long;

class Floyd {
public:
    constexpr static i64 INF = LONG_LONG_MAX / 2;

    int n;
    std::vector<std::vector<i64>> mat;
    std::vector<std::vector<i64>> dist;

    explicit Floyd(int n) : n(n) {
        mat.assign(n + 1, std::vector<i64>(n + 1, INF));
        dist.assign(n + 1, std::vector<i64>(n + 1));
        for (int i = 1; i <= n; i++) {
            mat[i][i] = 0;
        }
    }

    void addEdge(int u, int v, i64 w) {
        mat[u][v] = std::min(mat[u][v], w);
    }

    void go() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = mat[i][j];
            }
        }

        for (int bridge = 1; bridge <= n; bridge++) {
            for (int u = 1; u <= n; u++) {
                for (int v = 1; v <= n; v++) {
                    dist[u][v] = std::min(dist[u][v], dist[u][bridge] + dist[bridge][v]);
                }
            }
        }
    }
};
