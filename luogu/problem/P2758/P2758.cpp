#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int n = (int) s1.size(), m = (int) s2.size();
    std::vector f(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= m; i++) {
        f[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        f[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                f[i][j] = f[i - 1][j - 1];
                continue;
            }
            f[i][j] = std::min({f[i][j - 1] + 1, f[i - 1][j] + 1, f[i - 1][j - 1] + 1});
        }
    }

    std::cout << f[n][m] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
