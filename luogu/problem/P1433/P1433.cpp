#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    x.push_back(0);
    y.push_back(0);

    std::vector f(n + 1, std::vector<double>(1 << n, -1));
    auto dfs = [&](auto self, int i, int msk) -> double {
        if (!msk) {
            return 0;
        }

        auto &p = f[i][msk];
        if (p != -1) { return p; }

        auto res = DBL_MAX;
        for (int j = 0; j < n; j++) {
            if (msk & (1 << j)) {
                double dis = std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                res = std::min(res, self(self, j, msk ^ (1 << j)) + dis);
            }
        }

        return p = res;
    };

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << dfs(dfs, n, (1 << n) - 1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
