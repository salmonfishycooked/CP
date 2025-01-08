#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        int ans = n;
        std::vector<int> cnt(n + 1);
        for (int i = 0, v; i < n; i++) {
            std::cin >> v;
            cnt[v] += 1;
            ans = std::min(ans, n - cnt[v]);
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
