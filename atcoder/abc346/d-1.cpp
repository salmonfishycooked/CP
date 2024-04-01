/**
 * 记忆化搜索
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

    std::vector<std::vector<std::vector<i64>>> f(n, std::vector<std::vector<i64>>(2, std::vector<i64>(2, -1)));
    std::function<i64(int, int, int)> dfs = [&](int i, int need, int pre) -> i64 {
        if (i < 0) {
            if (need == 1) {
                return LONG_LONG_MAX / 2;
            }
            return 0;
        }

        i64 &p = f[i][need][pre];
        if (p != -1) {
            return p;
        }

        int ch = s[i] - '0';
        i64 res = dfs(i - 1, need, pre ^ 1) + (ch == pre ? c[i] : 0);
        if (need == 1) {
            res = std::min(res, dfs(i - 1, 0, pre) + (ch == pre ? 0 : c[i]));
        }
        return p = res;
    };

    std::cout << std::min(dfs(n - 2, 1, 1) + (s[n - 1] == '1' ? 0LL : c[n - 1]),
                          dfs(n - 2, 1, 0) + (s[n - 1] == '0' ? 0LL : c[n - 1])) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
