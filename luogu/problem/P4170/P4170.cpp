#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::string s;
    std::cin >> s;
    int n = (int) s.size();

    std::vector f(n, std::vector<int>(n, 1));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            if (s[i] == s[i + len - 1]) {
                f[i][i + len - 1] = f[i + 1][i + len - 1];
                continue;
            }
            f[i][i + len - 1] = INT_MAX;
            for (int j = i; j < i + len - 1; j++) {
                f[i][i + len - 1] = std::min(f[i][i + len - 1], f[i][j] + f[j + 1][i + len - 1]);
            }
        }
    }

    std::cout << f[0][n - 1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
