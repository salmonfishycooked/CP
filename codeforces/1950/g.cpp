#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::string> genres(n), writers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> genres[i] >> writers[i];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (genres[i] == genres[j] || writers[i] == writers[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    std::vector<std::vector<int>> f(1 << n, std::vector<int>(n, -1));
    std::function<int(int, int)> dfs;
    dfs = [&](int i, int start) -> int {
        if (f[i][start] != -1) {
            return f[i][start];
        }

        int res = 1;
        for (auto v : adj[start]) {
            if (i & (1 << v)) { continue; }
            res = std::max(res, dfs(i | (1 << v), v) + 1);
        }

        return f[i][start] = res;
    };

    int ans = n;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, n - dfs(1 << i, i));
    }

    std::cout << ans << '\n';
}

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
