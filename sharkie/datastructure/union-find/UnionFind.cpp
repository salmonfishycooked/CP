/**
 * Union-Find 并查集（带路径压缩）
 * 节点编号：1 ~ n
 *
 * 方法说明：
 * 1. void _union(int u, int v) 将 v 所属的集合合并到 u 所属的集合中
 * 2. int find(int u) 找到 u 所属集合的首领，并在查找过程中进行路径压缩
 */

#include <bits/stdc++.h>

class UnionFind {
public:
    int n;
    std::vector<int> fa;

    explicit UnionFind(int n) : n(n) {
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
