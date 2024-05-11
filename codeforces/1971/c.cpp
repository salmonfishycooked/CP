#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    if (x1 > y1) {
        std::swap(x1, y1);
    }

    if ((x2 > y1 || x2 < x1) && y2 > x1 && y2 < y1 ||
        (y2 > y1 || y2 < x1) && x2 > x1 && x2 < y1) {
        std::cout << "YES" << '\n';
        return;
    }
    std::cout << "NO" << '\n';
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
