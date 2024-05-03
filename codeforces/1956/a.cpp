#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int k, q;
    std::cin >> k >> q;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }

    int n;
    while (q--) {
        std::cin >> n;
        std::cout << std::min(n, a[0] - 1) << ' ';
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
