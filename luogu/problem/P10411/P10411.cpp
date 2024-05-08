#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int x, y;
    std::cin >> x;
    y = x;

    int divCnt = 0, mn = -1;
    bool hasOverSquare = false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) { continue; }

        int cnt = 0;
        for (; x % i == 0; x /= i) {
            cnt += 1;
        }
        hasOverSquare = hasOverSquare || cnt >= 2;

        divCnt += 1;
        mn = (mn == -1) ? i : mn;
    }
    divCnt += (x > 1);

    if (divCnt == 1) {
        std::cout << y << '\n';
        return;
    }
    if (hasOverSquare || divCnt % 2 == 0) {
        std::cout << 1 << '\n';
        return;
    }
    std::cout << mn << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
