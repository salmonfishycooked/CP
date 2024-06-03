#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int m, x;
    std::cin >> m >> x;

    int sumH = 0;
    std::vector<std::pair<int, int>> happy(m);
    for (int i = 0; i < m; i++) {
        std::cin >> happy[i].first >> happy[i].second;
        sumH += happy[i].second;
    }

    std::vector<i64> f(sumH + 1, LONG_LONG_MAX / 2);
    f[0] = 0;
    int ans = 0;
    i64 cur = 0;
    for (int i = 0; i < m; i++) {
        for (int j = sumH; j >= happy[i].second; j--) {
            i64 need = std::min(f[j], f[j - happy[i].second] + happy[i].first);
            if (need <= cur) {
                f[j] = need;
                ans = std::max(ans, j);
            }
        }
        cur += x;
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
