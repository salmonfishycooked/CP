#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, m;
        std::cin >> n >> m;

        int zeroBonus = 0;
        std::vector<int> pos, neg;
        for (int i = 0, v; i < n; ++i) {
            std::cin >> v;
            if (v == 0) { zeroBonus += 1; }
            if (v < 0) { neg.push_back(-v); }
            if (v > 0) { pos.push_back(v); }
        }

        std::sort(neg.begin(), neg.end());
        std::sort(pos.begin(), pos.end());

        int ans = 0;
        auto calc = [&](const std::vector<int> &from, const std::vector<int> &to) -> void {
            const int sz = static_cast<int>(from.size());
            for (int i = 0; i < sz; ++i) {
                const int dis = from[i];
                if (dis <= m) { ans = std::max(ans, i + 1 + zeroBonus); }
                if (dis * 2 > m) { continue; }

                const int remain = m - dis * 2;
                const int rightBorder = std::upper_bound(to.begin(), to.end(), remain) - to.begin();
                ans = std::max(ans, i + 1 + rightBorder + zeroBonus);
            }
        };

        calc(neg, pos);
        calc(pos, neg);

        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    s.solve();

    return 0;
}