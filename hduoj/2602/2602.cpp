/**
 * HDU 2602 - Bone Collector
 */

#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, v;
    std::cin >> n >> v;

    std::vector<int> values(n), volumes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> volumes[i];
    }

    std::vector f(v + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= volumes[i - 1]; j--) {
            f[j] = std::max(f[j], f[j - volumes[i - 1]] + values[i - 1]);
        }
    }

    std::cout << f[v] << '\n';
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
