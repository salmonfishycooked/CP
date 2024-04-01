/**
 * 记忆化搜索转递推
 */

#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::vector<std::vector<std::vector<i64>>> f(n + 1, std::vector<std::vector<i64>>(2, std::vector<i64>(2)));
    f[0][1][0] = f[0][1][1] = LONG_LONG_MAX / 2;
    f[0][0][0] = f[0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0][0] = f[i - 1][0][1] + (s[i - 1] == '0' ? c[i - 1] : 0);
        f[i][0][1] = f[i - 1][0][0] + (s[i - 1] == '1' ? c[i - 1] : 0);
        f[i][1][0] = std::min(f[i - 1][1][1] + (s[i - 1] == '0' ? c[i - 1] : 0), f[i - 1][0][0] + (s[i - 1] == '0' ? 0 : c[i - 1]));
        f[i][1][1] = std::min(f[i - 1][1][0] + (s[i - 1] == '1' ? c[i - 1] : 0), f[i - 1][0][1] + (s[i - 1] == '1' ? 0 : c[i - 1]));
    }

    std::cout << std::min(f[n - 1][1][0] + (s[n - 1] == '0' ? 0 : c[n - 1]), f[n - 1][1][1] + (s[n - 1] == '1' ? 0 : c[n - 1])) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
