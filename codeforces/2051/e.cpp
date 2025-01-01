#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }
        for (int i = 0; i < n; i++) { std::cin >> b[i]; }

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        auto getNeg = [&](i64 v) -> int {
            i64 buyCnt = n - (std::lower_bound(b.begin(), b.end(), v) - b.begin());
            i64 buyAndGivePosCnt = a.end() - std::lower_bound(a.begin(), a.end(), v);

            return buyCnt - buyAndGivePosCnt;
        };

        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            if (getNeg(a[i]) > k) { continue; }
            i64 buyCnt = n - (std::lower_bound(b.begin(), b.end(), a[i]) - b.begin());
            ans = std::max(ans, buyCnt * a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (getNeg(b[i]) > k) { continue; }
            i64 buyCnt = n - (std::lower_bound(b.begin(), b.end(), b[i]) - b.begin());
            ans = std::max(ans, buyCnt * b[i]);
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

    while (t--) {
        s.solve();
    }

    return 0;
}
