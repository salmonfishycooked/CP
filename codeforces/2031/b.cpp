#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 1; i <= n; i++) {
            mn = std::min(mn, a[i]);
            mx = std::max(mx, a[i]);
            if (mx - a[i] >= 2) {
                std::cout << "NO" << '\n';
                return;
            }
        }

        std::cout << "YES" << '\n';
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
