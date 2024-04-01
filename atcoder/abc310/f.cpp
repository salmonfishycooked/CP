#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 998244353;

i64 power(i64 x, int n) {
    i64 res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
    }

    return res;
}

void solve() {
    int N;
    std::cin >> N;

    std::vector<i64> A(N), inv(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        inv[i] = power(A[i], MOD - 2);
    }

    std::vector<std::vector<i64>> f(N, std::vector<i64>(1 << 10, -1));
    std::function<i64(int, int)> dfs;
    dfs = [&](int i, int msk) -> i64 {
        if (msk & (1 << 9)) { return 1; }
        if (i < 0) { return 0; }

        i64 &p = f[i][msk];
        if (p != -1) { return p; }

        i64 res = 0;
        for (int j = 1; j <= std::min(10LL, A[i]); j++) {
            res = (res + dfs(i - 1, (msk | (msk << j) | (1 << (j - 1))) & ((1 << 10) - 1)) * inv[i] % MOD) % MOD;
        }
        res = (res + dfs(i - 1, msk) * ((std::max(10LL, A[i]) - 10) * inv[i] % MOD) % MOD) % MOD;

        return p = res;
    };

    std::cout << dfs(N - 1, 0) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
