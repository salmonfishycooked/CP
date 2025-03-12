#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    std::vector<std::vector<int>> factors{101};

    Solution() {
        for (int i = 2; i <= 100; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (i % j != 0) { continue; }

                int another = i / j;
                if (j != i) { factors[i].push_back(j); }
                if (another != j && another != i) { factors[i].push_back(another); }
            }
        }
    }

    void solve() {
        int n, x;
        std::cin >> n >> x;

        std::vector<double> a(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }

        auto dfs = [&](auto self, std::vector<double> &nums) -> bool {
            int m = (int) nums.size();
            if (m == 1) { return nums[0] == x; }

            bool res = false;
            for (auto factor : factors[m]) {
                int seqNum = m / factor;
                std::vector<double> next(factor);
                double sum = 0;
                for (int i = 0; i < m; i++) {
                    if (i != 0 && i % seqNum == 0) {
                        next[i / seqNum - 1] = sum / seqNum;
                        sum = 0;
                    }
                    sum += nums[i];
                }
                next[factor - 1] = sum / seqNum;
                res = self(self, next);

                if (res) { break; }
            }

            return res;
        };

        std::cout << (dfs(dfs, a) ? "YES" : "NO") << '\n';
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
