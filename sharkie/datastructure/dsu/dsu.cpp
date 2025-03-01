/**
 * DSU(Disjoint Set Union) 并查集（带路径压缩）
 * 节点编号：1 ~ n
 *
 * 方法说明：
 * 1. bool merge(int u, int v) 将 v 所属的集合合并到 u 所属的集合中，如果 v 和 u 本身就属于同一个集合，返回 false，反之 true
 * 2. int find(int u) 找到 u 所属集合的首领，并在查找过程中进行路径压缩
 */

#include <bits/stdc++.h>

class DSU {
public:
    int n;
    std::vector<int> fa;

    explicit DSU(int n) : n(n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }

    bool merge(int u, int v) {
        int uFa = find(u), vFa = find(v);
        if (uFa == vFa) {
            return false;
        }

        fa[vFa] = uFa;
        return true;
    }

    int find(int u) {
        if (fa[u] != u) {
            return fa[u] = find(fa[u]);
        }
        return u;
    }
};
