#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<bool> occupied(n + 1, false);
    for (int i = 0, num; i < n; i++) {
        std::cin >> num;
        if (i == 0) {
            occupied[num] = true;
            continue;
        }

        if (num >= 2 && occupied[num - 1] || num < n && occupied[num + 1]) {
            occupied[num] = true;
            continue;
        }

        std::cout << "NO" << '\n';
        for (int j = i + 1; j < n; j++) { std::cin >> num; }
        return;
    }

    std::cout << "YES" << '\n';
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
