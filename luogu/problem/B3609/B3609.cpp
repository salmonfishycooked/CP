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
    int n, m;
    std::cin >> n >> m;

    SCC scc(n);
    for (int i = 0, u, v; i < m; i++) {
        std::cin >> u >> v;
        scc.addEdge(u, v);
    }

    scc.tarjan();

    for (auto &cur : scc.scc) {
        std::sort(cur.begin(), cur.end());
    }
    std::sort(scc.scc.begin(), scc.scc.end());

    std::cout << scc.scc.size() << '\n';
    for (auto &cur : scc.scc) {
        for (auto v : cur) {
            std::cout << v << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
