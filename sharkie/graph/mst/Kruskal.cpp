/**
 * 最小生成树 (Minimal Spanning Tree)
 * Kruskal 算法
 * 节点编号：1 ~ n
 *
 * 方法说明：
 * 1. void go() 开始 Kruskal 算法，返回最小生成树的边权之和，若返回 -1 则代表原图不连通。
 *
 * 模板 template <typename T = int> 代表边权采用什么类型存储，默认为 int
 *
 * 时间复杂度: O(mlogm), 其中 m 为总边数。
 */

#include <bits/stdc++.h>

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