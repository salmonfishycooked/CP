#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int N, M, T;
    std::cin >> N >> M >> T;

    std::vector<std::string> strs(N);
    for (auto &str : strs) {
        std::cin >> str;
    }

    std::vector g(N, std::vector(M, std::vector<int>(M)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = j; k < M; k++) {
                int cnt[2] = {0};
                for (int x = j; x <= k; x++) {
                    cnt[strs[i][x] - '0'] += 1;
                }
                g[i][j][k] = std::max(cnt[0], cnt[1]);
            }
        }
    }

    std::vector f(N, std::vector(M, std::vector<int>(T + 1, -1)));
    auto dfs = [&](auto self, int i, int pos, int times) -> int {
        if (times == 0) { return 0; }
        if (i < 0) { return 0; }
        if (pos == -1) { return self(self, i - 1, M - 1, times); }

        int &p = f[i][pos][times];
        if (p != -1) { return p; }

        int res = self(self, i, pos - 1, times);
        for (int j = pos; j >= 0; j--) {
            res = std::max(res, g[i][j][pos] + self(self, i, j - 1, times - 1));
        }

        return p = res;
    };

    std::cout << dfs(dfs, N - 1, M - 1, T) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
