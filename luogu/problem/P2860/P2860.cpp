#include <bits/stdc++.h>

using i64 = long long;

class EDCC {
public:
    int n;

    struct Edge {
        int to, edgeId;
    };
    std::vector<std::vector<Edge>> adj;

    std::vector<std::vector<int>> edcc;
    std::vector<int> belong;

    explicit EDCC(int _n) : n(_n) {
        adj.assign(n + 1, {});
        belong.resize(n + 1);
    }

    void addEdge(int u, int v, int edgeId) {
        adj[u].push_back({v, edgeId});
    }

    void go() {
        int timestamp = 1;
        std::vector<int> dfn(n + 1), low(n + 1);
        std::stack<int> stk;

        auto dfs = [&](auto self, int id, int fromEdge) -> void {
            dfn[id] = low[id] = timestamp++;
            stk.push(id);

            for (auto edge : adj[id]) {
                int to = edge.to, edgeId = edge.edgeId;
                if (!dfn[to]) {
                    self(self, to, edgeId);
                }
                if (edgeId != fromEdge) {
                    low[id] = std::min(low[id], low[to]);
                }
            }

            if (low[id] == dfn[id]) {
                std::vector<int> cur;
                while (true) {
                    int v = stk.top();
                    stk.pop();
                    cur.push_back(v);
                    belong[v] = edcc.size();
                    if (v == id) { break; }
                }
                edcc.push_back(cur);
            }
        };

        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) { dfs(dfs, i, -1); }
        }
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    EDCC edcc(n);
    for (int i = 0, u, v; i < m; i++) {
        std::cin >> u >> v;
        edcc.addEdge(u, v, i);
        edcc.addEdge(v, u, i);
    }

    edcc.go();

    int leaf = 0;
    for (int i = 0; i < edcc.edcc.size(); i++) {
        int eCut = 0;
        for (auto id : edcc.edcc[i]) {
            for (auto edge : edcc.adj[id]) {
                if (edcc.belong[edge.to] != edcc.belong[id]) {
                    eCut += 1;
                }
            }
        }
        leaf += eCut == 1;
    }

    std::cout << (leaf + 1) / 2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
