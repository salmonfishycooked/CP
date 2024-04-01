// 多源最短路径 (Multi-Source Shortest Path)
// Floyd
// 采用邻接矩阵存储图，结点编号为 1 ~ n
// 时间复杂度: O(n^3)，其中 n 为总顶点数。

// 1. dist[i] 代表从源点 i 开始到每个点的最短距离。dist[i][j] 代表源点 i 到点 j 的最短距离。
// 2. pre[i] 代表源点为 i 的路径前驱。pre[i][j] 代表从源点 i 到 j 的最短路径中，点 j 的路径前驱结点编号。

#include <bits/stdc++.h>

constexpr int INF = INT_MAX;

struct Floyd {
    int n;

    std::vector<std::vector<int>> mat;

    std::vector<std::vector<int>> dist;
    std::vector<std::vector<int>> pre;

    Floyd(int n) {
        this->n = n;
        mat.assign(n + 1, std::vector<int>(n + 1, INF));
        dist.assign(n + 1, std::vector<int>(n + 1, 0));
        pre.assign(n + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            mat[i][i] = 0;
        }
    };

    void addEdge(int u, int v, int weight) {
        mat[u][v] = weight;
    }

    void floyd() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = mat[i][j];
                if (dist[i][j] != INF && i != j) {
                    pre[i][j] = i;
                    continue;
                }
                pre[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (dist[j][i] == INF || dist[i][k] == INF) {
                        continue;
                    }
                    if (dist[j][k] > dist[j][i] + dist[i][k]) {
                        dist[j][k] = dist[j][i] + dist[i][k];
                        pre[j][k] = pre[i][k];
                    }
                }
            }
        }
    }
};
