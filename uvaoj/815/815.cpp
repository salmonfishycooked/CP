#include <bits/stdc++.h>

using i64 = long long;

constexpr double EPS = 1e-6;

void solve() {
    for (int round = 1; ; round++) {
        int n, m;
        std::cin >> n >> m;

        if (n == 0) { break; }

        int mx = 0, mn = INT_MAX;
        std::vector heights(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> heights[i][j];
                mx = std::max(mx, heights[i][j]);
                mn = std::min(mn, heights[i][j]);
            }
        }

        double volume;
        std::cin >> volume;

        auto getCurVolume = [&](double pos) -> double {
            double v = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (heights[i][j] <= pos) {
                        v += (pos - heights[i][j]) * 100;
                    }
                }
            }

            return v;
        };

        double l = mn, r = mx + (volume / (n * m * 100));
        while (r - l >= EPS) {
            double mid = (l + r) / 2;
            if (getCurVolume(mid) >= volume) {
                r = mid;
            } else {
                l = mid;
            }
        }

        int submerged = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (std::fabs(r - heights[i][j]) > EPS && r > heights[i][j]) {
                    submerged += 1;
                }
            }
        }

        std::cout << "Region " << round << '\n';
        std::cout << "Water level is " << std::fixed << std::setprecision(2) << (r + EPS) << " meters." << '\n';
        std::cout << std::fixed << std::setprecision(2) << ((double) submerged / (n * m) * 100) << " percent of the region is under water." << '\n';
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
