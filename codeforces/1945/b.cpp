#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, m;
    std::cin >> a >> b >> m;

    std::cout << m / a + 1 + m / b + 1 << '\n';
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
