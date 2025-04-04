#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        i64 n, m, k;
        std::cin >> n >> m >> k;

        auto check = [&](i64 v) -> bool {
            i64 groups = (m + 1) / (v + 1);
            i64 occupied = groups * (v + 1);
            i64 remain = std::max(0LL, m - occupied);

            return n * (groups * v + remain) >= k;
        };

        i64 l = 0, r = m + 1;
        while (l + 1 != r) {
            i64 mid = (l + r) >> 1;
            if (check(mid)) { r = mid; }
            else { l = mid; }
        }

        std::cout << r << '\n';
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
