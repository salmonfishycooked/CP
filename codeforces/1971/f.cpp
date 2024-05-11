#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    i64 r;
    std::cin >> r;

    int ans = 0;
    i64 pr = r * r, prr = (r + 1) * (r + 1);
    for (i64 x = 0; x <= r; x++) {
        i64 px = x * x;
        for (i64 y = std::ceil(std::sqrt(prr - px)); y >= 0; y--) {
            i64 dis = px + y * y;
            if (dis < pr) { break; }
            if (dis < prr) {
                ans += 1;
            }
        }
    }

    std::cout << (ans - 2) * 4 + 4 << '\n';
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
