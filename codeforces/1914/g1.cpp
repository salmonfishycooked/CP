/**
 * CF1914 G1 Light Bulbs (Easy Version)
 * 使用 Tarjan 算法求强连通分量
 * 其中建图时间复杂度 O(n^2)，Tarjan 算法时间复杂度 O(n)
 */

#include <bits/stdc++.h>

using i64 = int64_t;

constexpr int MOD = 998244353;

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

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> c(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> c[i];
    }

    SCC scc(n);
    for (int i = 1; i <= n; i++) {
        bool found = false;
        std::set<int> s;
        for (auto u : c) {
            if (u == i) {
                if (found) { break; }
                found = true;
                continue;
            }
            if (found) {
                s.insert(u);
            }
        }

        for (auto v : s) {
            scc.addEdge(i, v);
        }
    }

    scc.tarjan();

    std::vector<int> inDeg(scc.scc.size());
    for (int u = 1; u <= n; u++) {
        for (auto v : scc.adj[u]) {
            if (scc.belong[u] != scc.belong[v]) {
                inDeg[scc.belong[v]] += 1;
            }
        }
    }

    i64 mn = 0, cnt = 1;
    for (int i = 0; i < scc.scc.size(); i++) {
        if (inDeg[i] == 0) {
            mn += 1;
            cnt = (cnt * 2 * scc.scc[i].size()) % MOD;
        }
    }

    std::cout << mn << ' ' << cnt << '\n';
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
