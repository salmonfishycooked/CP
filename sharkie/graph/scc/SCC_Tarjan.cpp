/**
 * 求有向图中强连通分量 (Strongly Connected Component)
 * Tarjan 算法
 * 节点编号: 1 ~ n
 *
 * 变量说明：
 * 1. scc: 最终搜出来的每个强连通分量都会存入 scc
 * 2. belong: 查表，查询某个节点属于哪个 scc。例如 belong[2] = 0，代表编号为 2 的节点属于第 0 个 scc
 *
 * 方法说明：
 * 1. void tarjan() 在已有的图中跑 tarjan 算法
 *
 * 时间复杂度：O(n + m)，其中 n 为总节点数，m 为总边数。
 */

#include <bits/stdc++.h>

class SCC {
public:
    int n;
    std::vector<std::vector<int>> adj;

    std::vector<std::vector<int>> scc;
    std::vector<int> belong;

    explicit SCC(int _n) : n(_n) {
        adj.assign(n + 1, {});
        belong.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void tarjan() {
        int timestamp = 0;
        std::vector<int> dfn(n + 1), low(n + 1);
        std::vector<bool> inStack(n + 1);
        std::stack<int> stk;

        auto dfs = [&](auto self, int u) -> void {
            dfn[u] = low[u] = ++timestamp;
            inStack[u] = true;
            stk.push(u);

            for (auto v : adj[u]) {
                if (!dfn[v]) { self(self, v); }
                if (inStack[v]) {
                    low[u] = std::min(low[u], low[v]);
                }
            }

            if (dfn[u] == low[u]) {
                std::vector<int> cur;
                while (true) {
                    int v = stk.top();
                    stk.pop();
                    cur.push_back(v);
                    inStack[v] = false;
                    belong[v] = scc.size();
                    if (v == u) { break; }
                }
                scc.push_back(cur);
            }
        };

        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) { dfs(dfs, i); }
        }
    }
};
