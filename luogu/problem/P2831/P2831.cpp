#include <bits/stdc++.h>

using i64 = int64_t;

constexpr double EPS = 1e-8;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::vector<int> f(1 << n, -1);
    auto dfs = [&](auto self, int msk) -> int {
        if (!msk) {
            return 0;
        }

        int &p = f[msk];
        if (p != -1) { return p; }

        int res = INT_MAX;
        int p1 = __builtin_ffs(msk) - 1;
        msk -= (1 << p1);
        for (int p2 = 0; p2 < n; p2++) {
            if (msk & (1 << p2)) {
                double a = (x[p1] * y[p2] - x[p2] * y[p1]) / (x[p1] * x[p2] * (x[p2] - x[p1]));
                if (a > -EPS || x[p1] * x[p2] * (x[p2] - x[p1]) == 0) { continue; }
                double b = (x[p2] * x[p2] * y[p1] - x[p1] * x[p1] * y[p2]) / (x[p1] * x[p2] * (x[p2] - x[p1]));
                int curMsk = msk ^ (1 << p2);
                for (int i = 0; i < n; i++) {
                    if (curMsk & (1 << i) && std::fabs(a * x[i] * x[i] + b * x[i] - y[i]) < EPS) {
                        curMsk = curMsk ^ (1 << i);
                    }
                }
                res = std::min(res, self(self, curMsk) + 1);
            }
        }
        if (res == INT_MAX && msk) {
            res = self(self, msk) + 1;
        }

        return p = res == INT_MAX ? 1 : res;
    };

    std::cout << dfs(dfs, (1 << n) - 1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
