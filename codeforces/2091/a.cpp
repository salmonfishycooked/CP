#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        int ans = 0;
        std::vector<int> cnt(10);
        for (int i = 0, v; i < n; i++) {
            std::cin >> v;
            cnt[v] += 1;
            if (cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1) {
                ans = ans == 0 ? i + 1 : ans;
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
