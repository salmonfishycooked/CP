#include <bits/stdc++.h>

using i64 = int64_t;

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
                // condition: tree edge (son)
                if (!dfn[v]) {
                    self(self, v);
                    low[u] = std::min(low[u], low[v]);
                    continue;
                }
                // condition: back edge, cross edge, forward edge
                if (inStack[v]) {
                    low[u] = std::min(low[u], dfn[v]);
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
    int n, m;
    std::cin >> n >> m;

    SCC scc(n);
    for (int i = 0, u, v; i < m; i++) {
        std::cin >> u >> v;
        scc.addEdge(u, v);
    }

    scc.tarjan();

    std::vector<int> outDeg(scc.scc.size());
    for (int u = 1; u <= n; u++) {
        for (auto v : scc.adj[u]) {
            if (scc.belong[u] != scc.belong[v]) {
                outDeg[scc.belong[u]] += 1;
            }
        }
    }

    int cntSpot = 0, sccId;
    for (int i = 0; i < scc.scc.size(); i++) {
        if (outDeg[i] == 0) {
            cntSpot += 1;
            sccId = i;
        }
    }

    if (cntSpot > 1) {
        std::cout << 0 << '\n';
        return;
    }
    std::cout << scc.scc[sccId].size() << '\n';
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
