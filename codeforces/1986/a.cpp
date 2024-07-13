#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        ans = std::min(ans, std::abs(a[(i + 1) % 3] - a[i]) + std::abs(a[(i + 2) % 3] - a[i]));
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
