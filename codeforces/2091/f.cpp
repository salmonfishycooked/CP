#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 998244353;

class Solution {
public:
    void solve() {
        int n, m, d;
        std::cin >> n >> m >> d;

        int upperLevelR = (int) std::sqrt(d * d - 1);

        std::vector flag(n, std::vector<bool>(m, true));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                char ch;
                std::cin >> ch;
                if (ch == '#') { flag[i][j] = false; }
            }
        }

        std::vector<i64> diff(m + 1, 0), sum(m + 1, 0);
        diff[0] = 1;
        for (int i = 0; i < n; i++) {
            sum.assign(m + 1, 0);
            for (int j = 1; j <= m; j++) {
                sum[j] = (sum[j - 1] + diff[j - 1]) % MOD;
            }
            for (int j = 1; j <= m; j++) {
                if (!flag[i][j - 1]) { sum[j] = 0; }
                sum[j] = (sum[j] + sum[j - 1]) % MOD;
            }

            diff.assign(m + 1, 0);
            for (int j = 0; j < m; j++) {
                if (!flag[i][j]) { continue; }
                i64 devotion = (sum[std::min(j + 1 + d, m)] - sum[std::max(j - d, 0)] + MOD) % MOD;
                diff[std::max(j - upperLevelR, 0)] = (diff[std::max(j - upperLevelR, 0)] + devotion) % MOD;
                diff[std::min(j + upperLevelR + 1, m)] = (diff[std::min(j + upperLevelR + 1, m)] - devotion + MOD) % MOD;
            }
        }

        i64 ans = 0;
        for (int j = 0; j < m; j++) {
            if (!flag[n - 1][j]) { continue; }
            i64 devotion = (sum[std::min(j + 1 + d, m)] - sum[std::max(j - d, 0)] + MOD) % MOD;
            ans = (ans + devotion) % MOD;
        }

        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
