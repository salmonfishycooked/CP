#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, m;
        std::cin >> n >> m;

        std::vector<i64> a(n), r(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }
        for (int i = 0; i < n; i++) { std::cin >> r[i]; }

        std::map<int, i64> covered;
        for (int i = 0; i < n; i++) {
            int lx = a[i] - r[i], rx = a[i] + r[i];
            i64 r2 = (i64) r[i] * r[i];
            for (int curX = lx; curX <= rx; curX++) {
                covered[curX] = std::max(covered[curX], 2 * (i64) std::floor(std::sqrt(r2 - (a[i] - curX) * (a[i] - curX))) + 1);
            }
        }

        i64 ans = 0;
        for (auto [_, cnt] : covered) { ans += cnt; }

        std::cout << ans << '\n';
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
