#include <bits/stdc++.h>

using i64 = int64_t;

constexpr int MOD = 1e8;

int f[12][12][1 << 12];

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector grid(N, std::vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> grid[i][j];
        }
    }

    auto dfs = [&](auto self, int i, int j, int msk) -> int {
        if (i == N) {
            return 1;
        }
        if (j == M) {
            return self(self, i + 1, 0, msk);
        }

        auto &p = f[i][j][msk];
        if (p != 0) { return p; }

        int res = self(self, i, j + 1, msk & (~(1 << j)));
        if (grid[i][j] == '1' && !(msk & (1 << j))) {
            int nMsk = msk | (1 << j);
            if (j + 1 < M) {
                nMsk |= 1 << (j + 1);
            }
            res += self(self, i, j + 1, nMsk);
        }

        return p = res % MOD;
    };

    std::cout << dfs(dfs, 0, 0, 0) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
