/**
 * 洛谷P3092 [USACO13NOV] No Change G
 *
 * 状态压缩动态规划
 * dfs(msk) = 当前可选硬币二进制表示为 msk 的情况下，最多能顺序买到第多少件商品
 * dfs2(msk) = 当前可选硬币二进制表示为 msk 的情况下，顺序买下 N 件商品后，最多能剩下多少钱，若买不下 N 件商品，则返回 -1
 */
#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int K, N;
    std::cin >> K >> N;

    std::vector<int> coins(K);
    for (int i = 0; i < K; i++) {
        std::cin >> coins[i];
    }

    std::vector<int> sum(N + 1);
    for (int i = 1, num; i <= N; i++) {
        std::cin >> num;
        sum[i] += sum[i - 1] + num;
    }

    std::vector<int> f(1 << K, -1);
    auto dfs = [&](auto self, int msk) -> int {
        if (!msk) {
            return 0;
        }

        auto &p = f[msk];
        if (p != -1) { return p; }

        int res = 0;
        for (int i = 0; i < K; i++) {
            if (msk & (1 << i)) {
                int startPre = self(self, msk ^ (1 << i));
                int end = std::upper_bound(sum.begin(), sum.end(), coins[i] + sum[startPre]) - sum.begin();
                res = std::max(res, end - 1);
            }
        }

        return p = res;
    };

    std::vector<int> g(1 << K, -1);
    auto dfs2 = [&](auto self, int msk) -> int {
        if (dfs(dfs, msk) < N) {
            return -1;
        }

        auto &p = g[msk];
        if (p != -1) { return p; }

        int res = 0;
        for (int i = 0; i < K; i++) {
            if (msk & (1 << i)) {
                int after = self(self, msk ^ (1 << i));
                if (after != -1) {
                    res = std::max(res, after + coins[i]);
                }
            }
        }

        return p = res;
    };

    std::cout << dfs2(dfs2, (1 << K) - 1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
