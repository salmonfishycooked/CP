#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
    i64 n, m, s;
    std::cin >> n >> m >> s;

    std::vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> v[i];
    }

    std::vector<std::pair<int, int>> queries;
    for (int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        queries.emplace_back(l, r);
    }

    auto cal = [&](int W) -> i64 {
        std::vector<int> pre1(n + 1, 0);
        std::vector<i64> pre2(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre1[i] = pre1[i - 1] + (w[i - 1] >= W);
            pre2[i] = pre2[i - 1] + (w[i - 1] >= W ? v[i - 1] : 0);
        }

        i64 y = 0;
        for (int i = 0; i < m; i++) {
            auto [l, r] = queries[i];
            y += (pre1[r] - pre1[l - 1]) * (pre2[r] - pre2[l - 1]);
        }

        return y;
    };

    int l = 0, r = 1e6 + 2;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (cal(mid) > s) {
            l = mid;
        } else {
            r = mid;
        }
    }

    i64 ans = std::min(cal(l) - s, s - cal(r));
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
