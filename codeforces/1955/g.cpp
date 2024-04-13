#include <bits/stdc++.h>

using i64 = int64_t;

int grid[100][100], f[100][100];

void solve() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<int> divisor;
    for (int i = std::sqrt(grid[0][0]) + 1; i >= 1; i--) {
        if (grid[0][0] % i == 0) {
            divisor.push_back(i);
            divisor.push_back(grid[0][0] / i);
        }
    }

    auto check = [&](int div) -> bool {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i][j] = -1;
            }
        }

        auto dfs = [&](auto self, int x, int y) -> bool {
            if (x >= n || y >= m) {
                return false;
            }

            if (f[x][y] != -1) { return f[x][y]; }

            if (x == n - 1 && y == m - 1) {
                return f[x][y] = grid[x][y] % div == 0;
            }
            if (grid[x][y] % div != 0) {
                return f[x][y] = false;
            }
            return f[x][y] = self(self, x, y + 1) || self(self, x + 1, y);
        };

        return dfs(dfs, 0, 0);
    };

    int ans = 1;
    for (auto div : divisor) {
        if (ans >= div) { continue; }
        if (check(div)) {
            ans = div;
        }
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
