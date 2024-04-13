#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    if (a * 2 <= b) {
        std::cout << n * a << '\n';
        return;
    }

    std::cout << n / 2 * b + (n % 2 ? a : 0) << '\n';
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