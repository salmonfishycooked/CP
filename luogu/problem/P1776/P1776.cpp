#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, W;
    std::cin >> n >> W;

    std::vector<int> v(n), w(n), m(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i] >> w[i] >> m[i];
    }

    std::vector<int> f(W + 1);
    for (int i = 1; i <= n; i++) {
        int remain = m[i - 1];
        for (int j = 1; j <= remain; j <<= 1) {
            for (int k = W; k >= j * w[i - 1]; k--) {
                f[k] = std::max(f[k], f[k - j * w[i - 1]] + j * v[i - 1]);
            }
            remain -= j;
        }
        for (int k = W; k >= remain * w[i - 1]; k--) {
            f[k] = std::max(f[k], f[k - remain * w[i - 1]] + remain * v[i - 1]);
        }
    }

    std::cout << f[W] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
