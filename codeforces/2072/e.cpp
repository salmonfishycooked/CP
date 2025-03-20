#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int k;
        std::cin >> k;

        auto find = [&](int v) -> int {
            int l = 1, r = 1e3;
            while (l + 1 != r) {
                int mid = (r + l) >> 1;
                if ((mid * mid - mid) / 2 <= k) { l = mid; }
                else { r = mid; }
            }

            return l;
        };

        int y = 0;
        std::vector<std::pair<int, int>> points;
        for (int x = 0; k; x++) {
            int n = find(k);
            k -= (n * n - n) / 2;
            for (int times = 0; times < n; times++, y++) { points.emplace_back(x, y); }
        }

        std::cout << points.size() << '\n';
        for (auto [x, y] : points) { std::cout << x << ' ' << y << '\n'; }
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
