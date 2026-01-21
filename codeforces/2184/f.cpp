#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> tree(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u; --v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        auto dfs = [&](auto self, int me, int fa) -> std::vector<bool> {
            if (me != 0 && tree[me].size() == 1) {
                return {false, true, false};
            }

            std::vector<bool> f_old = {true, false, false}, f_new(3, false);
            for (const auto child : tree[me]) {
                if (child == fa) { continue; }

                const std::vector<bool> v = self(self, child, me);
                for (int i = 0; i < 3; ++i) {
                    if (!v[i]) { continue; }
                    f_new[0] = f_new[0] || f_old[(0 - i + 3) % 3];
                    f_new[1] = f_new[1] || f_old[(1 - i + 3) % 3];
                    f_new[2] = f_new[2] || f_old[(2 - i + 3) % 3];
                }
                f_old = std::move(f_new);
                f_new = {false, false, false};
            }

            return { f_old[0], true, f_old[2] };
        };

        const std::vector<bool> v = dfs(dfs, 0, -1);

        std::cout << (v[0] ? "YES" : "NO") << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}