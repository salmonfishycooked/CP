#include <bits/stdc++.h>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a < b && b < c) {
        std::cout << "STAIR" << '\n';
        return;
    }
    if (a < b && b > c) {
        std::cout << "PEAK" << '\n';
        return;
    }
    std::cout << "NONE" << '\n';
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
