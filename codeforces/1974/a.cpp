#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int x, y;
    std::cin >> x >> y;

    int need = y / 2 + y % 2;
    int remain = std::max(x - (need * 15 - y * 4), 0);
    need += remain / 15 + (remain % 15 != 0);

    std::cout << need << '\n';
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