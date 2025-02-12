#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, k;
        std::cin >> n >> k;

        int ans = 0;
        std::vector<int> cnt(n + 1);
        for (int i = 0, v; i < n; i++) {
            std::cin >> v;
            if (k - v >= 1 && k - v <= n && cnt[k - v] > 0) {
                cnt[k - v] -= 1;
                ans += 1;
            } else {
                cnt[v] += 1;
            }
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
