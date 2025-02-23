#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> mp(n * m);
        for (int i = 0, v; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> v;
                mp[v] = i;
            }
        }

        std::vector<int> ans(n, -1);
        for (int i = 0; i < n * m; i++) {
            if (i < n) {
                if (ans[i] != -1) {
                    std::cout << -1 << '\n';
                    return;
                }
                ans[i] = mp[i];
                continue;
            }
            if (ans[i % n] != mp[i]) {
                std::cout << -1 << '\n';
                return;
            }
        }

        for (auto order : ans) { std::cout << order + 1 << ' '; }
        std::cout << '\n';
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
