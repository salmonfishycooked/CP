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
    int n, m, mod;
    std::cin >> n >> m >> mod;

    SCC scc(n);
    for (int i = 0, u, v; i < m; i++) {
        std::cin >> u >> v;
        scc.addEdge(u, v);
    }

    scc.tarjan();

    int ans = 0, wayAns = 0, timestamp = 0;
    std::vector<int> f(scc.scc.size()), way(scc.scc.size(), 1), vis(scc.scc.size());
    for (int i = scc.scc.size() - 1; i >= 0; i--) {
        timestamp += 1;
        f[i] += scc.scc[i].size();
        vis[i] = timestamp;
        for (auto u : scc.scc[i]) {
            for (auto v : scc.adj[u]) {
                if (vis[scc.belong[v]] == timestamp) { continue; }

                vis[scc.belong[v]] = timestamp;
                if (f[i] > f[scc.belong[v]]) {
                    f[scc.belong[v]] = f[i];
                    way[scc.belong[v]] = 0;
                }
                if (f[i] == f[scc.belong[v]]) {
                    way[scc.belong[v]] = (way[scc.belong[v]] + way[i]) % mod;
                }
            }
        }

        if (f[i] > ans) {
            ans = f[i];
            wayAns = 0;
        }
        if (f[i] == ans) {
            wayAns = (wayAns + way[i]) % mod;
        }
    }

    std::cout << ans << '\n' << wayAns;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
