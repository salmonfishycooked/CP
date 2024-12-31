/**
 * 最小树形图 (Directed Minimum Spanning Tree)
 * 朱刘算法
 * 节点编号：1 ~ n
 *
 * 方法说明：
 * 1. bool go(int root) 代表以编号 root 为根，开始朱刘算法，返回 true 代表存在最小树形图，false 代表不存在
 *
 * 参数说明：
 * 1. sum 代表朱刘算法正确结束后（也就是存在最小树形图的时候），对应的最小树形图的所有边权之和
 *
 * 时间复杂度: O(nm)。其中 n 为总顶点数，m 为总边数。
 */

#include <bits/stdc++.h>

using i64 = long long;

class ZhuLiu {
public:
    struct Edge {
        int u, v;
        i64 w;
    };

    int n;
    std::vector<Edge> edges;

    i64 sum;

    explicit ZhuLiu(const int n) : n(n), sum(0) {}

    void addEdge(const int u, const int v, const i64 w) {
        edges.push_back({u, v, w});
    }

    bool go(int root) {
        std::vector<int> belong(n + 1);
        for (int i = 1; i <= n; i++) { belong[i] = i; }

        std::vector<int> pre(n + 1, -1);
        std::vector<i64> weigh(n + 1, 0);

        int stkPtr = -1;
        std::vector<int> stk(n + 1);
        std::vector<bool> vis(n + 1, false);
        std::vector<bool> inStack(n + 1, false);

        int tot = n;
        while (true) {
            for (auto [u, v, w] : edges) {
                if (u != v && (pre[v] == -1 || w < weigh[v])) {
                    pre[v] = u;
                    weigh[v] = w;
                }
            }

            pre[root] = -1, weigh[root] = 0;
            for (int block = 1; block <= tot; block++) {
                if (block != root && pre[block] == -1) {
                    return false;
                }
                sum += weigh[block];
            }

            for (int i = 1; i <= tot; i++) { belong[i] = -1; }

            int loopCnt = 0;
            for (int block = 1; block <= tot; block++) {
                if (vis[block]) { continue; }

                for (int curBlock = block; curBlock != -1; curBlock = pre[curBlock]) {
                    if (inStack[curBlock]) {
                        loopCnt += 1;
                        while (stk[stkPtr] != curBlock) {
                            belong[stk[stkPtr]] = loopCnt;
                            inStack[stk[stkPtr]] = false;
                            stkPtr -= 1;
                        }
                        belong[curBlock] = loopCnt;
                        break;
                    }
                    if (vis[curBlock]) { break; }

                    vis[curBlock] = true;
                    inStack[curBlock] = true;
                    stk[++stkPtr] = curBlock;
                }

                while (stkPtr >= 0) {
                    inStack[stk[stkPtr]] = false;
                    stkPtr -= 1;
                }
            }
            if (loopCnt == 0) { break; }

            for (int block = 1; block <= tot; block++) {
                if (belong[block] == -1) {
                    belong[block] = ++loopCnt;
                }
            }
            tot = loopCnt;

            for (auto &edge : edges) {
                int u = edge.u, v = edge.v;
                edge.u = belong[u], edge.v = belong[v];
                if (belong[u] != belong[v]) {
                    edge.w -= weigh[v];
                }
            }

            root = belong[root];
            for (int block = 1; block <= loopCnt; block++) { vis[block] = false; }
            for (int block = 1; block <= loopCnt; block++) { pre[block] = -1; }
        }

        return true;
    }
};
