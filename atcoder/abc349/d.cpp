#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    i64 l, r;
    std::cin >> l >> r;

    int cnt = 0;
    std::vector<std::pair<i64, i64>> ans;
    while (l < r) {
        int x = (int) std::log2(r - l) + 1;
        for (int i = x; i >= 0; i--) {
            i64 p = std::pow(2, i);
            if (l + p > r) {
                continue;
            }
            if (l % p == 0) {
                cnt += 1;
                ans.emplace_back(l, l + p);
                l = l + p;
                break;
            }
        }
    }

    std::cout << cnt << '\n';
    for (auto [x, y] : ans) {
        std::cout << x << ' ' << y << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
