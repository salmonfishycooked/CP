#include <bits/stdc++.h>

using i64 = int64_t;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::string A, B;
    std::cin >> A >> B;

    std::vector f(std::vector(m + 1, std::vector(k + 1, std::vector<int>(2))));
    f[0][0][0] = 1, f[0][1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            for (int w = k; w >= 1; w--) {
                f[j][w][0] = f[j][w][0];
                f[j][w][1] = f[j][w - 1][0];
                if (A[i - 1] == B[j - 1]) {
                    f[j][w][0] += f[j - 1][w][1]; f[j][w][0] %= MOD;
                    f[j][w][1] += (f[j - 1][w][1] + f[j - 1][w - 1][1]) % MOD; f[j][w][1] %= MOD;
                }
            }
        }
    }

    std::cout << f[m][k][0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
