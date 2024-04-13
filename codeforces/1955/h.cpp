#include <bits/stdc++.h>

using i64 = int64_t;

std::tuple<int, int, int> towers[2500];

std::pair<int, int> paths[2500];
int pathCnt;

int powerThree[13];
int devotion[2500][13];
int f[2500][1 << 12];

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    pathCnt = 0;
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> ch;
            if (ch == '#') {
                paths[pathCnt++] = {i, j};
            }
        }
    }

    for (int i = 0; i < k; i++) {
        auto &[x, y, p] = towers[i];
        std::cin >> x >> y >> p;
        x--; y--;
    }

    for (int i = 0; i < k; i++) {
        auto [x, y, p] = towers[i];
        for (int r = 0; r <= 12; r++) {
            int curH = -powerThree[r];
            if (r == 0) { curH = 0; }
            int cnt = 0;
            for (int j = 0; j < pathCnt; j++) {
                auto [ex, ey] = paths[j];
                if ((ex - x) * (ex - x) + (ey - y) * (ey - y) <= r * r) {
                    cnt += 1;
                }
            }
            devotion[i][r] = curH + cnt * p;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (1 << 12); j++) {
            f[i][j] = -1;
        }
    }
    auto dfs = [&](auto self, int i, int msk) -> int {
        if (i < 0) {
            return 0;
        }

        if (f[i][msk] != - 1) { return f[i][msk]; }

        int res = self(self, i - 1, msk) + devotion[i][0];
        for (int j = 0; j < 12; j++) {
            if (msk & (1 << j)) {
                res = std::max(res, self(self, i - 1, msk ^ (1 << j)) + devotion[i][j + 1]);
            }
        }

        return f[i][msk] = res;
    };

    std::cout << dfs(dfs, k - 1, (1 << 12) - 1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    powerThree[0] = 1;
    for (int i = 1; i <= 12; i++) {
        powerThree[i] = powerThree[i - 1] * 3;
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
