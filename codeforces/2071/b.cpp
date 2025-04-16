#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    std::set<i64> square;
    Solution() {
        for (i64 i = 1; i * i <= 2e11; i++) { square.insert(i * i); }
    }

    void solve() {
        i64 n;
        std::cin >> n;

        if (square.contains(n * (n + 1) / 2)) {
            std::cout << -1 << '\n';
            return;
        }

        std::vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) { ans[i] = i; }
        for (int i = 1; i <= n; i++) {
            if (square.contains((i64) i * (i + 1) / 2)) {
                std::swap(ans[i], ans[i + 1]);
            }
            std::cout << ans[i] << ' ';
        }
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
