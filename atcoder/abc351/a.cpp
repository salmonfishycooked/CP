#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int totalA = 0;
    for (int i = 0, tmp; i < 9; i++) {
        std::cin >> tmp;
        totalA += tmp;
    }

    int totalB = 0;
    for (int i = 0, tmp; i < 8; i++) {
        std::cin >> tmp;
        totalB += tmp;
    }

    std::cout << totalA - totalB + 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
