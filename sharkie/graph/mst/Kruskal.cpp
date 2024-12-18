/**
 * 最小生成树 (Minimum Spanning Tree)
 * Kruskal 算法
 * 节点编号：1 ~ n
 *
 * 方法说明：
 * 1. bool go() 开始 Kruskal 算法，返回 true 代表原图连通，false 代表不连通
 *
 * 参数说明：
 * 1. sum 代表 Kruskal 算法正确结束后（也就是原图连通），对应的最小生成树的所有边权之和
 *
 * 时间复杂度: O(mlogm), 其中 m 为总边数。
 */

#include <bits/stdc++.h>

using i64 = long long;

class UnionFind {
public:
    int n;
    std::vector<int> fa;

    explicit UnionFind(const int n) : n(n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }

    int find(const int u) {
        if (fa[u] != u) {
            return fa[u] = find(fa[u]);
        }

        return u;
    }

    void _union(const int u, const int v) {
        const int uFa = find(u), vFa = find(v);
        fa[vFa] = uFa;
    }
};

class Kruskal {
public:
    struct Edge {
        int from, to;
        i64 w;
    };
    int n;
    std::vector<Edge> edges;

    i64 sum;

    explicit Kruskal(int _n) : n(_n) {}

    void addEdge(int from, int to, i64 weight) {
        edges.push_back({from, to, weight});
    }

    bool go() {
        UnionFind uf(n);

        std::sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b) -> bool {
            return a.w < b.w;
        });

        int tot = n;
        sum = 0;
        for (auto &edge : edges) {
            int from = edge.from, to = edge.to;
            if (uf.find(from) != uf.find(to)) {
                uf._union(from, to);
                sum += edge.w;
                tot -= 1;
            }
            if (tot == 1) {
                break;
            }
        }

        return tot == 1;
    }
};
