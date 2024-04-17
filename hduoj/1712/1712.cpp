/**
 * HDU 1712 - ACboy needs your help
 */

#include <bits/stdc++.h>

using i64 = int64_t;

void solve(int n, int m) {
    std::vector A(n, std::vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector f(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= j; k++) {
                f[j] = std::max(f[j], f[j - k] + A[i - 1][k]);
            }
        }
    }

    std::cout << f[m] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m && n && m) {
        solve(n, m);
    }

    return 0;
}
