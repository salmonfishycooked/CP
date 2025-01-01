#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        i64 n, x, y, sum = 0;
        std::cin >> n >> x >> y;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum += a[i];
        }
        std::sort(a.begin(), a.end());

        i64 cnt = 0;
        for (int i = 0; i < n; i++) {
            i64 mn = sum - a[i] - y, mx = sum - a[i] - x;
            cnt += std::upper_bound(a.begin(), a.begin() + i, mx) - std::lower_bound(a.begin(), a.begin() + i, mn);
        }
        std::cout << cnt << '\n';
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
