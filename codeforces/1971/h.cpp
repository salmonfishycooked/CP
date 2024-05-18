#include <bits/stdc++.h>

using i64 = int64_t;

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

    bool isSatisfied() {
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

void solve() {
    int n;
    std::cin >> n;

    std::vector grid(3, std::vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    TwoSat ts(n);
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < 3; r++) {
            int next = (r + 1) % 3;
            ts.addClause(std::abs(grid[r][c]), grid[r][c] > 0, std::abs(grid[next][c]), grid[next][c] > 0);
        }
    }

    if (ts.isSatisfied()) {
        std::cout << "Yes" << '\n';
        return;
    }
    std::cout << "No" << '\n';
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
