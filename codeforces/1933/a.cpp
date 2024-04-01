#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    int ans = 0, tmp;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        ans += std::abs(tmp);
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
