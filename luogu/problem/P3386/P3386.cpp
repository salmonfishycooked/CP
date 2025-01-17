#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, m, e;
        std::cin >> n >> m >> e;

        std::vector mat(n, std::vector<int>(m));
        for (int i = 0, u, v; i < e; i++) {
            std::cin >> u >> v;
            u--; v--;
            mat[u][v] = 1;
        }

        std::vector<int> matched(m, -1);
        auto match = [&](int me) -> bool {
            std::vector<bool> vis(n);
            auto dfs = [&](auto self, int me) -> bool {
                for (int to = 0; to < m; to++) {
                    if (!mat[me][to] || vis[to]) { continue; }
                    vis[to] = true;
                    if (matched[to] == -1 || self(self, matched[to])) {
                        matched[to] = me;
                        return true;
                    }
                }

                return false;
            };

            return dfs(dfs, me);
        };

        int ans = 0;
        for (int i = 0; i < n; i++) { ans += match(i); }

        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
