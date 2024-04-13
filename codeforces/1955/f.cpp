#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int p1, p2, p3, p4;
    std::cin >> p1 >> p2 >> p3 >> p4;

    int ans = p1 / 2 + p2 / 2 + p3 / 2 + p4 / 2;
    p1 -= p1 / 2 * 2;
    p2 -= p2 / 2 * 2;
    p3 -= p3 / 2 * 2;
    ans += std::min({p1, p2, p3});
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
