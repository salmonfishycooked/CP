#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        std::string s;
        std::cin >> s;

        int n = s.length();

        std::vector f(2, std::vector(26, std::vector<int>(n, -1)));
        auto dfs = [&](auto self, int i, int ch, int mode) -> int {
            if (i == n) {
                return mode ? INT_MAX / 2 : 0;
            }

            int &p = f[mode][ch][i];
            if (p != -1) { return p; }

            int res = INT_MAX / 2;
            if (!mode) {
                res = std::min(res, self(self, i + 1, 0, 0) + 1);
                res = std::min(res, self(self, i + 1, s[i] - 'a', 1));
            } else {
                if (s[i] - 'a' == ch) {
                    res = std::min(res, self(self, i + 1, 0, 0));
                } else {
                    res = std::min(res, self(self, i + 1, ch, 1) + 1);
                }
            }

            return p = res;
        };

        std::cout << dfs(dfs, 0, 0, 0) << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >>t;

    while (t--) {
        s.solve();
    }

    return 0;
}
