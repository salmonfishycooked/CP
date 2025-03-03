#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<i64> pre(n + 1), suf(n + 2);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1];
            if (a[i - 1] > 0) {
                pre[i] += a[i - 1];
            }
        }

        for (int i = n; i >= 1; i--) {
            suf[i] = suf[i + 1];
            if (a[i - 1] < 0) {
                suf[i] -= a[i - 1];
            }
        }

        i64 ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = std::max(ans, pre[i] + suf[i + 1]);
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
