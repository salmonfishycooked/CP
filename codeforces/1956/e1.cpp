#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n == 2) {
        while (a[0] != 0 && a[1] != 0) {
            a[1] = std::max(a[1] - a[0], 0);
            a[0] = std::max(a[0] - a[1], 0);
        }
        for (int i = 0; i < 2; i++) {
            if (a[i]) {
                std::cout << 1 << '\n' << i + 1 << '\n';
                return;
            }
        }
        std::cout << 0 << '\n' << '\n';
        return;
    }

    auto check = [&]() -> bool {
        for (int i = 0; i < n; i++) {
            if (a[i] && a[(i + 1) % n] && a[(i + 2) % n]) {
                return true;
            }
        }

        return false;
    };

    while (check()) {
        for (int i = 1; i <= n; i++) {
            a[i % n] = std::max(a[i % n] - a[i - 1], 0);
        }
    }

    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && a[(i - 1 + n) % n] == 0) {
            ans.push_back(i + 1);
        }
    }

    std::cout << ans.size() << '\n';
    for (auto idx : ans) {
        std::cout << idx << ' ';
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
