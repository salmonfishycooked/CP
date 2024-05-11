#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int a, b;
    std::cin >> a >> b;

    if (a > b) {
        std::swap(a, b);
    }

    std::cout << a << ' ' << b << '\n';
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
