#include <bits/stdc++.h>

using i64 = int64_t;

int sum[501];

void solve() {
    int n;
    std::cin >> n;

    std::cout << sum[n] << ' ' << 2 * n - 1 << '\n';

    auto printP = [&]() -> void {
        for (int i = 1; i <= n; i++) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    };

    std::cout << 1 << ' ' << n << ' ';
    printP();
    for (int i = n - 1; i >= 1; i--) {
        for (int mode = 1; mode <= 2; mode++) {
            std::cout << mode << ' ' << i << ' ';
            printP();
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sum[1] = 1;
    for (int i = 2; i <= 500; i++) {
        sum[i] = sum[i - 1] + (2 * i - 1) * i;
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
