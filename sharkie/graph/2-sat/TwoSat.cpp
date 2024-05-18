/**
 * 2-SAT (2-Satisfiability)
 * 节点编号：1 ~ 2*n
 *
 * 方法说明：
 * 1. 构造方法 TwoSat(int _n)，_n 代表布尔变量的总数
 * 2. void addClause(int u, bool condU, int v, bool condV)，添加约束条件，u，v 分别为布尔变量的编号（范围 1 ~ n），
 *    condU，condV 分别为它们对应的约束条件。
 * 3. bool satisfiable()，检查这 n 个布尔变量是否有一种赋值方法使其满足所有的约束条件，并将每个变量的赋值存入 ans 中。
 *
 * 参数说明：
 * 1. ans 里面存储一种赋值方案，使得 n 个布尔变量满足所有的约束条件。
 */

#include <bits/stdc++.h>

class TwoSat {
public:
    int n;
    int sccCnt;
    std::vector<std::vector<int>> adj;
    std::vector<int> belong;
    std::vector<bool> ans;

    explicit TwoSat(int _n) : n(_n), sccCnt(0) {
        adj.assign(2 * n + 1, {});
        belong.resize(2 * n + 1);
        ans.resize(n + 1);
    }

    void addClause(int u, bool condU, int v, bool condV) {
        adj[2 * u - !condU].push_back(2 * v - condV);
        adj[2 * v - !condV].push_back(2 * u - condU);
    }

    bool satisfiable() {
        tarjan();
        for (int i = 1; i <= n; i++) {
            if (belong[2 * i - 1] == belong[2 * i]) {
                return false;
            }
            ans[i] = belong[2 * i - 1] < belong[2 * i];
        }

        return true;
    }
private:
    void tarjan() {
        sccCnt = 0;

        int timestamp = 0;
        std::vector<int> dfn(2 * n + 1), low(2 * n + 1);
        std::vector<bool> inStack(2 * n + 1);
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
                while (true) {
                    int v = stk.top();
                    stk.pop();
                    inStack[v] = false;
                    belong[v] = sccCnt;
                    if (v == u) { break; }
                }
                sccCnt += 1;
            }
        };

        for (int i = 1; i <= 2 * n; i++) {
            if (!dfn[i]) { dfs(dfs, i); }
        }
    }
};
