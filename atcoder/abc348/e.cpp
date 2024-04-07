#include <bits/stdc++.h>

using i64 = int64_t;

struct Node {
    std::vector<int> adj;
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<Node> tree(n);
    for (int i = 1, u, v; i < n; i++) {
        std::cin >> u >> v;
        u--; v--;
        tree[u].adj.push_back(v);
        tree[v].adj.push_back(u);
    }

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) { std::cin >> c[i]; }

    std::vector<i64> f(n), g(n);
    auto dfs1 = [&](auto self, int me, int from) -> void {
        for (auto to : tree[me].adj) {
            if (to == from) { continue; }
            self(self, to, me);
            g[me] += g[to];
            f[me] += f[to] + g[to];
        }
        g[me] += c[me];
    };
    dfs1(dfs1, 0, -1);

    std::vector<i64> v(n);
    auto dfs2 = [&](auto self, int me, int from) -> void {
        if (from != -1) {
            v[me] = f[from] + v[from] - g[me] - f[me] + g[0] - g[me];
        }
        for (auto to : tree[me].adj) {
            if (to == from) { continue; }
            self(self, to, me);
        }
    };
    dfs2(dfs2, 0, -1);

    i64 ans = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, f[i] + v[i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
