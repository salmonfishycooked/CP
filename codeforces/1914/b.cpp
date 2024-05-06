#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, k;
    std::cin >> n >> k;

    for (int i = n - k; i <= n; i++) {
        std::cout << i << ' ';
    }
    for (int i = n - k - 1; i >= 1; i--) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
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
