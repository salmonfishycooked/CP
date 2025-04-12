#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        int mx = 0, mn = INT_MAX;
        for (int i = 0, v; i < n; i++) {
            std::cin >> v;
            mx = std::max(mx, v);
            mn = std::min(mn, v);
        }

        std::cout << mx - mn << '\n';
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
