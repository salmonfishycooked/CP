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
    int N, R, C;
    std::cin >> N >> R >> C;

    int tot = N;
    std::map<std::pair<int, int>, int> id;
    std::vector<int> X(N + 1), Y(N + 1), T(N + 1);
    std::map<int, std::vector<int>> row, col;
    for (int i = 1; i <= N; i++) {
        std::cin >> X[i] >> Y[i] >> T[i];
        if (!row.count(X[i])) { tot += 1; }
        if (!col.count(Y[i])) { tot += 1; }
        row[X[i]].push_back(i);
        col[Y[i]].push_back(i);
        id[{X[i], Y[i]}] = i;
    }

    SCC scc(tot);
    int number = N;
    std::map<int, int> rowSupId, colSupId;
    for (int i = 1; i <= N; i++) {
        switch (T[i]) {
            case 1: {
                if (!rowSupId.count(X[i])) {
                    rowSupId[X[i]] = ++number;
                    for (auto v : row[X[i]]) {
                        scc.addEdge(number, v);
                    }
                }
                scc.addEdge(i, rowSupId[X[i]]);
                break;
            }
            case 2: {
                if (!colSupId.count(Y[i])) {
                    colSupId[Y[i]] = ++number;
                    for (auto v : col[Y[i]]) {
                        scc.addEdge(number, v);
                    }
                }
                scc.addEdge(i, colSupId[Y[i]]);
                break;
            }
            default: {
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) { continue; }
                        int nx = X[i] + dx, ny = Y[i] + dy;
                        auto it = id.find({nx, ny});
                        if (it != id.end()) {
                            scc.addEdge(i, it->second);
                        }
                    }
                }
            }
        }
    }

    scc.tarjan();

    int ans = 0;
    std::vector<int> f(scc.scc.size());
    for (int i = 0; i < scc.scc.size(); i++) {
        int sz = 0;
        for (auto from : scc.scc[i]) {
            if (from <= N) { sz += 1; }
            for (auto to : scc.adj[from]) {
                if (scc.belong[from] == scc.belong[to]) { continue; }
                f[i] = std::max(f[i], f[scc.belong[to]]);
            }
        }
        f[i] += sz;
        ans = std::max(ans, f[i]);
    }

    std::cout << ans << '\n';
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
