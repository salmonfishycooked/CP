#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if ((a + b + c) % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }
    if (c <= a + b) {
        std::cout << (a + b + c) / 2 << '\n';
        return;
    }
    std::cout << a + b << '\n';
};

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
