#include <bits/stdc++.h>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int ans = a + b / 3;
    b = b - 3 * (b / 3);
    if (b == 1 && c < 2 || b == 2 && c < 1) {
        std::cout << "-1" << '\n';
        return;
    }
    ans += (b + c) / 3;
    ans += (b + c) % 3 != 0;
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
